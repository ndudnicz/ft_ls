/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_parse_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:51 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:52 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "compare.h"
#include "misc.h"
#include "display_long.h"
#include "free.h"
#include "entry_list_long.h"
#include "entry_init_long.h"
#include "entry_push_sort.h"

/*
** thx 42 norme.
*/

static t_entry		*make_root_norme(t_var_box *vb)
{
	char			*newpath;
	struct stat		s[2];
	t_entry			*new;

	newpath = NULL;
	new = NULL;
	if (!(newpath = ft_strjoin_free(ft_strjoin(vb->path, "/"),
	vb->dp->d_name, 1, 0)))
		return (pft_error(vb->exec_name, "", MALLOC_FAILED, NULL));
	stat(newpath, &s[0]);
	lstat(newpath, &s[1]);
	if (!(new = create_long_entry(s, vb->dp, newpath)))
		return (pft_error(vb->exec_name, "", MALLOC_FAILED, NULL));
	set_date(vb->ctx, new, &s[1]);
	if (push_sort_entry(vb->begin, &new, vb->ctx->sort_ptr)
	== NULL)
		return (pft_error(vb->exec_name, "", UNKNOWN_ERROR, NULL));
	free((void*)newpath);
	return (new);
}

static void			set_sizes(
	t_context *ctx,
	t_entry **bgn,
	t_entry *new
)
{
	t_u64 const		usr_len = ft_strlen(new->entry_long->username);
	t_u64 const		grp_len = ft_strlen(new->entry_long->grp_name);

	new->data = (*bgn)->data;
	if ((ctx->options & OPT_DOT_FILES) || new->name[0] != '.')
	{
		if (new->lstat.st_nlink > (*bgn)->data->entry_long->sizes.biggest_nlink)
		{
			(*bgn)->data->entry_long->sizes.biggest_nlink = new->lstat.st_nlink;
			(*bgn)->data->entry_long->sizes.biggest_nlink_len =
			ft_numberlen(new->lstat.st_nlink, 10);
		}
		if (new->lstat.st_size > (*bgn)->data->entry_long->sizes.biggest_size)
		{
			(*bgn)->data->entry_long->sizes.biggest_size = new->lstat.st_size;
			(*bgn)->data->entry_long->sizes.biggest_size_len =
			ft_numberlen(new->lstat.st_size, 10);
		}
		if (usr_len > (*bgn)->data->entry_long->sizes.biggest_usr_len)
			(*bgn)->data->entry_long->sizes.biggest_usr_len = usr_len;
		if (grp_len > (*bgn)->data->entry_long->sizes.biggest_grp_len)
			(*bgn)->data->entry_long->sizes.biggest_grp_len = grp_len;
	}
	(*bgn)->data->entry_long->total += new->lstat.st_blocks;
}

/*
** Make entries of the given path
** t_var_box: thx 42 norme.
*/

static t_entry		*make_root(
	t_context *ctx,
	char *exec_name,
	t_entry **begin,
	char *path
)
{
	DIR				*dirp;
	t_var_box		vb;
	t_entry			*new;

	dirp = NULL;
	vb.ctx = ctx;
	vb.exec_name = exec_name;
	vb.begin = begin;
	vb.path = path;
	if ((dirp = opendir(path)) == NULL)
		return (pft_perror(exec_name, path, NULL));
	while ((vb.dp = readdir(dirp)) != NULL)
	{
		if (!vb.dp)
			return (pft_error(exec_name, "", READDIR_FAILED, NULL));
		if (!(!(ctx->options & OPT_DOT_FILES) && vb.dp->d_name[0] == '.' &&
		vb.dp->d_name[1]))
		{
			if (!(new = make_root_norme(&vb)))
				return (NULL);
			set_sizes(ctx, vb.begin, new);
		}
	}
	(void)closedir(dirp);
	return (*begin);
}

/*
** Make entries, starting at the given path, but for the -l long format
*/

t_entry				*make_entries_long(
	t_context *ctx,
	t_entry *begin,
	char *path
)
{
	t_entry		*next;

	make_root(ctx, ctx->exec_name, &begin, path);
	if (begin && ((ctx->options & OPT_DOT_FILES) || begin->next))
	{
		ft_putstr("total ");
		ft_putuint64(begin->data->entry_long->total);
		ft_putchar('\n');
	}
	display_root_entries_long(ctx->options, begin);
	while (begin)
	{
		next = begin->next;
		free_entry_long(&begin);
		begin = next;
	}
	return (begin);
}

/*
** Make entries recursively, starting at the given path, but for the -l
** long format
*/

t_entry				*make_entries_recursive_long(
	t_context *ctx,
	t_entry *begin,
	char *path
)
{
	t_entry		*next;

	make_root(ctx, ctx->exec_name, &begin, path);
	if (begin && ((ctx->options & OPT_DOT_FILES) || begin->next))
	{
		ft_putstr("total ");
		ft_putuint64(begin->data->entry_long->total);
		ft_putchar('\n');
	}
	if (display_root_entries_long(ctx->options, begin))
		return (NULL);
	while (begin)
	{
		if (!(begin->mode & MODE_IS_SYM) && (begin->mode & MODE_IS_NODE) &&
		!is_dot_double_dot(begin->name))
		{
			print_3_strings("\n", begin->fullname, ":\n");
			make_entries_recursive_long(ctx, begin->node, begin->fullname);
		}
		next = begin->next;
		free_entry_long(&begin);
		begin = next;
	}
	return (begin);
}
