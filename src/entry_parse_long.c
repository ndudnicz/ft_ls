#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "compare.h"
#include "misc.h"
#include "display.h"
#include "free.h"
#include "entry_list_long.h"
#include "entry_push_sort.h"

/*
** thx 42 norme.
*/
static t_entry		*make_root_norme(t_var_box *vb)
{
	char			*newpath;
	struct stat 	s[2];
	t_entry			*new;
	// t_u8 const		options = vb->ctx->options;

	newpath = NULL;
	new = NULL;
	if (!(newpath = ft_strjoin_free(ft_strjoin(vb->path, "/"),
	vb->dp->d_name, 1, 0)))
		return (pft_error(vb->exec_name, "", MALLOC_FAILED, NULL));
	stat(newpath, &s[0]);
	lstat(newpath, &s[1]);
	if (!(new = create_long_entry(vb->begin, s, vb->dp, newpath)))
		return (pft_error(vb->exec_name, "", MALLOC_FAILED, NULL));
	if (push_sort_entry(vb->begin, &new, vb->ctx->sort_ptr)
	== NULL)
		return (pft_error(vb->exec_name, "", UNKNOWN_ERROR, NULL));
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
		return (pft_perror(exec_name, path, NULL));
	while ((vb.dp = readdir(dirp)) != NULL)
	{
		if (!vb.dp)
			return (pft_error(exec_name, "", READDIR_FAILED, NULL));
		if (!(!(ctx->options & OPT_DOT_FILES) && vb.dp->d_name[0] == '.' &&
		vb.dp->d_name[1]))
		{
			if (!make_root_norme(&vb))
				return (NULL);
		}
	}
	(void)closedir(dirp);
	return (*begin);
}

/*
** Make entries, starting at the given path, but for the -l long format
*/
t_entry					*make_entries_long(
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
** Make entries recursively, starting at the given path, but for the -l
** long format
*/
t_entry					*make_entries_recursive_long(
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
		if (!(begin->mode & MODE_IS_SYM) && (begin->mode & MODE_IS_NODE) && !is_dot_double_dot(begin->name))
		{
			ft_putchar('\n');
			ft_putstr(begin->fullname);
			ft_putendl(":");
			make_entries_recursive_long(ctx, begin->node, begin->fullname);
		}
		next = begin->next;
		free_entry(&begin);
		begin = next;
	}
	return (begin);
}
