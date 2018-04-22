#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "compare.h"
#include "misc.h"
#include "display.h"

#include <stdio.h>

__attribute__((always_inline)) static void	free_entry(t_entry **entry)
{
	free((*entry)->fullname);
	(*entry)->fullname = NULL;
	free((*entry)->name);
	(*entry)->name = NULL;
	free((*entry));
	*entry = NULL;
}

__attribute__((always_inline)) static void	make_root_init_stack(
	DIR				**dirp,
	t_entry			**new,
	struct dirent	**dp,
	char			**newpath
)
{
	*newpath = NULL;
	*dirp = NULL;
	*new = NULL;
	*dp = NULL;
}

static t_entry			*make_root(
	t_u8 const options,
	char const * const exec_name,
	t_entry **begin,
	char const * const path
)
{
	struct stat 	s;
	DIR				*dirp;
	t_entry			*new;
	struct dirent	*dp;
	char			*newpath;

	make_root_init_stack(&dirp, &new, &dp, &newpath);
	if ((dirp = opendir(path)) == NULL)
		return (pft_perror(exec_name, path, NULL));
	while ((dp = readdir(dirp)) != NULL)
	{
		if (!dp)
			return (pft_error(exec_name, "", READDIR_FAILED, NULL));
		if (!(!(options & OPT_DOT_FILES) && dp->d_name[0] == '.' && dp->d_name[1]))
		{
			if (!(newpath = ft_strjoin_free(ft_strjoin(path, "/"), dp->d_name, 1, 0)))
				return (pft_error(exec_name, "", MALLOC_FAILED, NULL));
			stat(newpath, &s);
			if (!(new = create_entry(/**begin ? (*begin)->length : */0, &s, dp, newpath)))
				return (pft_error(exec_name, "", MALLOC_FAILED, NULL));
			if (push_sort_entry(begin, &new, &compare_lex_standard) == NULL)
				return (pft_error(exec_name, "", UNKNOWN_ERROR, NULL));
			free((void*)newpath);
		}
	}
	(void)closedir(dirp);
	return (*begin);
}

t_entry					*make_entries(
	t_context *ctx,
	t_entry *begin,
	char const * const path
)
{
	t_entry		*next;

		make_root(ctx->options, ctx->exec_name, &begin, path);
		display_root_entries(ctx->options, begin);
	if (ctx->options & OPT_RECURSIVE)
	{
		// make_root(ctx->options, ctx->exec_name, &begin, path);
		// display_root_entries(ctx->options, begin);
		while (begin)
		{
			if ((begin->mode & MODE_IS_NODE) && !is_dot_double_dot(begin->name))
			{
				ft_putchar('\n');
				ft_putstr(begin->fullname);
				ft_putendl(":");
				make_entries(ctx, begin->node, begin->fullname);
			}
			next = begin->next;
			free_entry(&begin);
			begin = next;
		}
	}
	else
	{
		// make_root(ctx->options, ctx->exec_name, &begin, path);
		// display_root_entries(ctx->options, begin);
		while (begin)
		{
			// ft_puts(begin->name);
			next = begin->next;
			free_entry(&begin);
			begin = next;
		}
	}
	return (begin);
}
