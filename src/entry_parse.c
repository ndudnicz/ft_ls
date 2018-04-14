#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "compare.h"

static void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

/*
** Recursive function that follow nodes and generate file trees
*/
#include <stdio.h>//
t_entry		*make_node_entry(
	t_context const *ctx,
	t_entry **begin,
	char const * const path,
	char make_node
)
{
	struct stat 	s;
	DIR				*dirp;
	t_entry			*new;
	t_entry			*node;
	struct dirent	*dp;
	char			*newpath;

	ft_memset(&newpath, 0, sizeof(DIR*) + sizeof(t_entry*) + sizeof(struct dirent*) + sizeof(char*));

	if (!(dirp = opendir(path)))
		return (pft_perror(ctx->exec_name, path, NULL));

	while ((dp = readdir(dirp)) != NULL) {
		if (!dp)
			return (NULL);
		if (!(ctx->options & OPT_DOT_FILES) && dp->d_name[0] == '.' && dp->d_name[1])
		{
			printf("jump dot file: %s\n", dp->d_name);
			continue ;
		}

		if (!(newpath = ft_strjoin_free(ft_strjoin_free(path, "/", 0, 0), dp->d_name, 1, 0)))
			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));

		stat(newpath, &s);
		if (!begin || !dp || !newpath)
			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));

		new = create_entry((*begin) ? (*begin)->length : 0, &s, dp, newpath);
		if (*begin && (*begin)->mode & MODE_IS_NODE)
			(*begin)->node = new;

		/* REVERSE */
		if ((ctx->options & OPT_REVERSE) && push_sort_entry(begin, &new, &compare_reverse) == NULL)
			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
		else if (!(ctx->options & OPT_REVERSE) && push_sort_entry(begin, &new, &compare_standard) == NULL)
			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));

		/* RECURSIVE */
		if ((ctx->options & OPT_RECURSIVE) && ft_strcmp(CUR_DIR_STR, new->name)
		&& ft_strcmp(PARENT_DIR_STR, new->name) && (new->mode & MODE_IS_NODE))
		{

			make_node_entry(ctx, &new, newpath, 1);
		}
		free((void*)newpath);

	}
	(void)closedir(dirp);
	return (*begin);
}
