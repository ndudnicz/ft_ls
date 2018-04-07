#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"

static void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

/*
** Recursive function that follow nodes and generate file trees
*/
t_entry		*make_node_entry(
	t_context const *ctx,
	t_entry **begin,
	char const * const path
)
{
	struct stat 	s;
	DIR				*dirp;
	t_entry			*new;
	struct dirent	*dp;
	char			*newpath;

	ft_memset(&newpath, 0,
	sizeof(DIR*) + sizeof(t_entry*) + sizeof(struct dirent*) + sizeof(char*));
	printf("%p\n%p\n%p\n%p\n", &dirp, &new, &dp, &newpath);
	if (!(dirp = opendir(path)))
		return (pft_perror(ctx->exec_name, path, NULL));
	while ((dp = readdir(dirp)) != NULL) {
		if (!dp || !dp->d_name)
			return (NULL);
		if (!(newpath = ft_strjoin_free(ft_strjoin(path, "/"), dp->d_name, 1, 0)))
			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));
		stat(newpath, &s);


		if (!begin || !dp || !newpath)
			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
		new = create_entry((*begin) ? (*begin)->length : 0, &s, dp, NULL);


		// if (push_back_entry(begin, &new) == NULL)
		// 	return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
		// if ((ctx->options & OPT_RECURSIVE) && ft_strcmp(CUR_DIR_STR, new->name)
		// && ft_strcmp(PARENT_DIR_STR, new->name) && (new->mode & MODE_IS_NODE))
		// 	make_node_entry(ctx, &new, newpath);
		// free((void*)newpath);
	}
	(void)closedir(dirp);
	return (*begin);
}
