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
#include <errno.h>

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
#include "set_sizes.h"

static t_entry		*solo_file(
	t_context *ctx,
	char const *const path
)
{
	t_entry		*new;
	struct stat	ls[2];

	stat(path, &ls[0]);
	lstat(path, &ls[1]);
	new = create_long_entry(ctx, ls, path, path);
	if (set_date(ctx, &new, &ls[1]))
		return (NULL);
	new->data = new;
	new->entry_long->sizes.biggest_nlink = new->lstat.st_nlink;
	new->entry_long->sizes.biggest_nlink_len =
	ft_numberlen(new->lstat.st_nlink, 10);
	new->entry_long->sizes.biggest_size = new->lstat.st_size;
	new->entry_long->sizes.biggest_size_len =
	ft_numberlen(new->lstat.st_size, 10);
	new->entry_long->sizes.biggest_usr_len =
	ft_strlen(new->entry_long->username);
	new->entry_long->sizes.biggest_grp_len =
	ft_strlen(new->entry_long->grp_name);
	display_root_entries_long(ctx->options, new);
	free_entry_long(&new);
	return (NULL);
}

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
	if (!(newpath = ft_strjoin_free(ft_strjoin(vb->path,
	ft_strcmp("/", vb->path) ? "/": ""),
	vb->dp->d_name, 1, 0)))
		return (pft_free_perror(vb->ctx, &new, vb->path, NULL));
	stat(newpath, &s[0]);
	lstat(newpath, &s[1]);
	if (!(new = create_long_entry(vb->ctx, s, vb->dp->d_name, newpath)))
	{
		free((void*)newpath);
		return (NULL);
	}
	set_date(vb->ctx, &new, &s[1]);
	if (push_sort_entry(vb->begin, &new, vb->ctx->sort_ptr) == NULL)
		return (pft_free_perror(vb->ctx, &new, vb->path, NULL));
	free((void*)newpath);
	set_sizes(vb->ctx, vb->begin, new);
	return (new);
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
	new = NULL;
	vb.ctx = ctx;
	vb.exec_name = exec_name;
	vb.begin = begin;
	vb.path = path;
	if ((dirp = opendir(path)) == NULL && errno && errno != 20)
		return (pft_free_perror(ctx, &new, path, NULL));
	else if (dirp == NULL)
		return (solo_file(ctx, path));
	while ((vb.dp = readdir(dirp)) != NULL)
	{
		if (!(!(ctx->options & OPT_DOT_FILES) && vb.dp->d_name[0] == '.' &&
		vb.dp->d_name[1]) && !(new = make_root_norme(&vb)))
		{
			(void)closedir(dirp);
			return (NULL);
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
