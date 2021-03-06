/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:45 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:46 by ndudnicz         ###   ########.fr       */
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
#include "display.h"
#include "free.h"
#include "entry_list.h"
#include "entry_push_sort.h"

static t_entry		*solo_file(
	t_context *ctx,
	char const *const path
)
{
	t_entry		*new;
	struct stat	ls[2];

	lstat(path, &ls[0]);
	new = create_entry(ctx, ls, path, path);
	display_root_entries(ctx->options, new);
	free_entry(&new);
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
	if (!(newpath = ft_strjoin_free(ft_strjoin(vb->path, "/"),
	vb->dp->d_name, 1, 0)))
		return (pft_free_perror(vb->ctx, &new, vb->path, NULL));
	stat(newpath, &s[0]);
	lstat(newpath, &s[1]);
	if (!(new = create_entry(vb->ctx, s, vb->dp->d_name, newpath)))
	{
		free((void*)newpath);
		return (pft_free_perror(vb->ctx, &new, vb->path, NULL));
	}
	if (push_sort_entry(vb->begin, &new, vb->ctx->sort_ptr)
	== NULL)
		return (pft_free_perror(vb->ctx, &new, vb->path, NULL));
	free((void*)newpath);
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

	dirp = NULL;
	vb.ctx = ctx;
	vb.exec_name = exec_name;
	vb.begin = begin;
	vb.path = path;
	if ((dirp = opendir(path)) == NULL)
		return (errno && errno != 20 ? pft_free_perror(ctx, NULL, path, NULL) :
		solo_file(ctx, path));
	else
	{
		while ((vb.dp = readdir(dirp)) != NULL)
		{
			if (!(!(ctx->options & OPT_DOT_FILES) && vb.dp->d_name[0] == '.' &&
			vb.dp->d_name[1]) && !make_root_norme(&vb))
			{
				(void)closedir(dirp);
				return (NULL);
			}
		}
		(void)closedir(dirp);
		return (*begin);
	}
}

/*
** Make entries, starting at the given path
*/

t_entry				*make_entries(
	t_context *ctx,
	t_entry *begin,
	char *path
)
{
	t_entry		*next;

	make_root(ctx, ctx->exec_name, &begin, path);
	display_root_entries(ctx->options, begin);
	while (begin)
	{
		next = begin->next;
		free_entry(&begin);
		begin = next;
	}
	return (begin);
}

/*
** Make entries recursively, starting at the given path
*/

t_entry				*make_entries_recursive(
	t_context *ctx,
	t_entry *begin,
	char *path
)
{
	t_entry		*next;

	make_root(ctx, ctx->exec_name, &begin, path);
	display_root_entries(ctx->options, begin);
	while (begin)
	{
		if (!(begin->mode & MODE_IS_SYM) && (begin->mode & MODE_IS_NODE) &&
		!is_dot_double_dot(begin->name))
		{
			ft_putchar('\n');
			ft_putstr(begin->fullname);
			ft_putendl(":");
			make_entries_recursive(ctx, begin->node, begin->fullname);
		}
		next = begin->next;
		free_entry(&begin);
		begin = next;
	}
	return (begin);
}
