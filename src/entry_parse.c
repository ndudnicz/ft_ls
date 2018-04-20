#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "compare.h"
#include "misc.h"
#include "display.h"

#include <stdio.h>

t_entry		*make_root(t_u8 const options, char const * const exec_name, t_entry **begin, char const * const path)
{
	struct stat 	s;
	DIR				*dirp;
	t_entry			*new;
	// t_entry			*node;
	struct dirent	*dp;
	char			*newpath;

	ft_memset(&newpath, 0, sizeof(DIR*) + sizeof(t_entry*) + sizeof(struct dirent*) + sizeof(char*));

	if (!(dirp = opendir(path)))
		return (pft_perror(exec_name, path, NULL));

	while ((dp = readdir(dirp)) != NULL) {
		if (!dp)
		{
			puts("aaa");
			return (NULL);

		}
		if (!(options & OPT_DOT_FILES) && dp->d_name[0] == '.' && dp->d_name[1])
			continue ;

		if (!(newpath = ft_strjoin_free(ft_strjoin(path, "/"), dp->d_name, 1, 0)))
			return (pft_error(exec_name, "", MALLOC_FAILED, NULL));

		stat(newpath, &s);
		if (/*!begin || */!newpath){
			// printf("%p %p\n", begin, newpath);
			return (pft_error(exec_name, "", UNKNOWN_ERROR, NULL));
		}
		if (!(new = create_entry(/**begin ? (*begin)->length : */0, &s, dp, newpath)))
			return (pft_error(exec_name, "", MALLOC_FAILED, NULL));
		// printf("new: %s\n", new->name);


		/* REVERSE */
		// puts("standard");
		// printf("%p\n", *begin);
		if (push_sort_entry(begin, &new, &compare_lex_standard) == NULL)
			return (pft_error(exec_name, "", UNKNOWN_ERROR, NULL));
		// printf("%p\n", *begin);
		free((void*)newpath);

	}
	// printf("->%p\n", ctx);
	(void)closedir(dirp);
	return (*begin);
	// return (NULL);
}

t_entry		*make_entries(t_context volatile ctx, t_entry *begin, char const * const path)
{
	t_u8 const volatile options = ctx.options;
	char const * const volatile exec_name = ctx.exec_name;

	if (options & OPT_RECURSIVE)
	{
		printf("%d\n", options);
		make_root(options, exec_name, &begin, path);
		display_root_entries(options, begin);
		while (begin)
		{
			if ((begin->mode & MODE_IS_NODE) && !is_dot_double_dot(begin->name))
			{
				ft_putchar('\n');
				ft_putstr(begin->fullname);
				ft_putendl(":");
				make_entries(ctx, begin->node, begin->fullname);
			}
			begin = begin->next;
		}
	}
	else
	{
		make_root(ctx.options, ctx.exec_name, &begin, path);
		display_root_entries(ctx.options, begin);

	}
	return (begin);
}
