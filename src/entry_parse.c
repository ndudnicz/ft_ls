#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "compare.h"
#include "misc.h"
#include "display.h"

#include <stdio.h>
// static void	*ft_free(void *ptr)
// {
// 	free(ptr);
// 	return (NULL);
// }

// t_entry		*make_root_entries(
// 	t_context const *ctx,
// 	t_entry **begin,
// 	char const * const path
// 	// char make_node
// )
// {
// 	struct stat 	s;
// 	DIR				*dirp;
// 	t_entry			*new;
// 	t_entry			*node;
// 	struct dirent	*dp;
// 	char			*newpath;
//
// 	ft_memset(&newpath, 0, sizeof(DIR*) + sizeof(t_entry*) + sizeof(struct dirent*) + sizeof(char*));
//
// 	if (!(dirp = opendir(path)))
// 		return (pft_perror(ctx->exec_name, path, NULL));
//
// 	while ((dp = readdir(dirp)) != NULL) {
// 		if (!dp)
// 			return (NULL);
// 		if (!(ctx->options & OPT_DOT_FILES) && dp->d_name[0] == '.' && dp->d_name[1])
// 			continue ;
//
// 		if (!(newpath = ft_strjoin_free(ft_strjoin(path, "/"), dp->d_name, 1, 0)))
// 			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));
//
// 		stat(newpath, &s);
// 		if (!begin || !dp || !newpath)
// 			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
//
//
// 		if (!(new = create_entry((*begin) ? (*begin)->length : 0, &s, dp, newpath)))
// 			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));
//
//
// 		/* REVERSE */
// 		if ((ctx->options & OPT_REVERSE))
// 		{
// 			if (ctx->options & OPT_SORT_TIME)
// 			{
// 				// puts("a");
// 				if (push_sort_entry(begin, &new, &compare_time_modified_reverse) == NULL)
// 					return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 			}
// 			else
// 			{
// 				// puts("b");
// 				if (push_sort_entry(begin, &new, &compare_lex_reverse) == NULL)
// 					return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 			}
// 		}
// 		else
// 		{
// 			if (ctx->options & OPT_SORT_TIME)
// 			{
// 				// puts("c");
// 				if (push_sort_entry(begin, &new, &compare_time_modified) == NULL)
// 					return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 			}
// 			else
// 			{
// 				puts("d");
// 				if (push_sort_entry(begin, &new, &compare_lex_standard) == NULL)
// 					return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 			}
// 		}
// 		free((void*)newpath);
// 	}
// 		// display_entries(ctx, begin);
// 	if ((ctx->options & OPT_RECURSIVE)/* && (dp->d_namlen > 2 || !is_dot_double_dot(new->name)) && (new->mode & MODE_IS_NODE)*/)
// 	{
// 		// display_entries(ctx, begin);
// 		if (make_root_childs_entries(ctx, begin, path))
// 			return (NULL);
// 		else
// 			return (*begin);
// 	}
// 	else
// 	{
// 		// display_entries(ctx, begin);
// 		(void)closedir(dirp);
// 		return (*begin);
// 	}
// }
//
// t_entry		*make_root_childs_entries(
// 	t_context const *ctx,
// 	t_entry **begin,
// 	char const * const path
// 	// char make_node
// )
// {
// 			// display_entries_debug(ctx, begin, 0);
// 	while (*begin)
// 	{
// 		if ((ctx->options & OPT_RECURSIVE) && !is_dot_double_dot((*begin)->name) && ((*begin)->mode & MODE_IS_NODE))
// 		{
// 			if (!make_node_entry(ctx, &(*begin)->node, (*begin)->fullname, 1))
// 			{
// 				return (NULL);
// 			}
// 			// display_entries_debug(ctx, begin, 0);
// 		}
// 		// else
// 		// {
//
// 		// }
// 		*begin = (*begin)->next;
// 	}
// }
//
// /*
// ** Recursive function that follow nodes and generate file trees
// */
// t_entry		*make_node_entry(
// 	t_context const *ctx,
// 	t_entry **begin,
// 	char const * const path,
// 	char make_node
// )
// {
// 	struct stat 	s;
// 	DIR				*dirp;
// 	t_entry			*new;
// 	t_entry			*node;
// 	struct dirent	*dp;
// 	char			*newpath;
//
// 	ft_memset(&newpath, 0, sizeof(DIR*) + sizeof(t_entry*) + sizeof(struct dirent*) + sizeof(char*));
//
// 	if (!(dirp = opendir(path)))
// 		return (pft_perror(ctx->exec_name, path, NULL));
//
// 	while ((dp = readdir(dirp)) != NULL) {
// 		if (!dp)
// 			return (NULL);
// 		if (!(ctx->options & OPT_DOT_FILES) && dp->d_name[0] == '.' && dp->d_name[1])
// 			continue ;
//
// 		if (!(newpath = ft_strjoin_free(ft_strjoin(path, "/"), dp->d_name, 1, 0)))
// 			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));
//
// 		stat(newpath, &s);
// 		if (!begin || !dp || !newpath)
// 			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
//
// 		new = create_entry((*begin) ? (*begin)->length : 0, &s, dp, newpath);
// 		if (!new)
// 			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));
//
//
// 		/* REVERSE */
// 		if ((ctx->options & OPT_REVERSE))
// 		{
// 			if (ctx->options & OPT_SORT_TIME)
// 			{
// 				// puts("sort time reverse");
// 				if (push_sort_entry(begin, &new, &compare_time_modified_reverse) == NULL)
// 					return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 			}
// 			else
// 			{
// 				// puts("reverse");
// 				if (push_sort_entry(begin, &new, &compare_lex_reverse) == NULL)
// 					return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 			}
// 		}
// 		else
// 		{
// 			if (ctx->options & OPT_SORT_TIME)
// 			{
// 				// puts("sort time");
// 				if (push_sort_entry(begin, &new, &compare_time_modified) == NULL)
// 					return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 			}
// 			else
// 			{
// 				// puts("standard");
// 				if (push_sort_entry(begin, &new, &compare_lex_standard) == NULL)
// 					return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 			}
// 		}
// 		// if ( && push_sort_entry(begin, &new, &compare_lex_reverse) == NULL)
// 		// 	return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 		// else if (!(ctx->options & OPT_REVERSE) && push_sort_entry(begin, &new, &compare_lex_standard) == NULL)
// 		// 	return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
//
// 		/* RECURSIVE */
// 		if ((ctx->options & OPT_RECURSIVE) && (dp->d_namlen > 2 || !is_dot_double_dot(new->name)) && (new->mode & MODE_IS_NODE))
// 		{
// 			printf("A------>%p\n", *begin);
// 			make_node_entry(ctx, &new->node, newpath, 1);
// 			printf("B------>%p\n", *begin);
// 		}
// 		free((void*)newpath);
//
// 	}
// 	(void)closedir(dirp);
// 	return (*begin);
// }

t_entry		*make_root(t_context *ctx, t_entry **begin, char const * const path)
{
	struct stat 	s;
	DIR				*dirp;
	t_entry			*new;
	// t_entry			*node;
	struct dirent	*dp;
	char			*newpath;

	ft_memset(&newpath, 0, sizeof(DIR*) + sizeof(t_entry*) + sizeof(struct dirent*) + sizeof(char*));

	if (!(dirp = opendir(path)))
	return (pft_perror(ctx->exec_name, path, NULL));

	while ((dp = readdir(dirp)) != NULL) {
		if (!dp)
		{
			puts("aaa");
			return (NULL);

		}
		if (!(ctx->options & OPT_DOT_FILES) && dp->d_name[0] == '.' && dp->d_name[1])
			continue ;

		if (!(newpath = ft_strjoin_free(ft_strjoin(path, "/"), dp->d_name, 1, 0)))
			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));

		stat(newpath, &s);
		if (/*!begin || */!newpath){
			// printf("%p %p\n", begin, newpath);
			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
		}
		if (!(new = create_entry(/**begin ? (*begin)->length : */0, &s, dp, newpath)))
			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));
		// printf("new: %s\n", new->name);


		/* REVERSE */
		// puts("standard");
		if (push_back_entry(begin, &new/*, &compare_lex_standard*/) == NULL)
			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
		free((void*)newpath);

	}
	(void)closedir(dirp);
	return (*begin);
}

t_entry		*make_entries(t_context *ctx, t_entry **begin, char const * const path)
{
	make_root(ctx, begin, path);
	display_root_entries(ctx, begin);
	while ((ctx->options & OPT_RECURSIVE) && *begin)
	{
		if (((*begin)->mode & MODE_IS_NODE) && !is_dot_double_dot((*begin)->name))
		{
			printf("rec:%s\n", (*begin)->fullname);
			// make_root(ctx, &(*begin)->node, (*begin)->fullname);
			make_entries(ctx, &(*begin)->node, (*begin)->fullname);
		}
		*begin = (*begin)->next;
	}
	return (*begin);
}

// t_entry		*make_entries(t_context *ctx, t_entry **begin, char const * const path)
// {
// 	struct stat 	s;
// 	DIR				*dirp;
// 	t_entry			*new;
// 	// t_entry			*node;
// 	struct dirent	*dp;
// 	char			*newpath;
//
// 	ft_memset(&newpath, 0, sizeof(DIR*) + sizeof(t_entry*) + sizeof(struct dirent*) + sizeof(char*));
//
// 	if (!(dirp = opendir(path)))
// 	return (pft_perror(ctx->exec_name, path, NULL));
//
// 	while ((dp = readdir(dirp)) != NULL) {
// 		if (!dp)
// 		{
// 			puts("aaa");
// 			return (NULL);
//
// 		}
// 		if (!(ctx->options & OPT_DOT_FILES) && dp->d_name[0] == '.' && dp->d_name[1])
// 			continue ;
//
// 		if (!(newpath = ft_strjoin_free(ft_strjoin(path, "/"), dp->d_name, 1, 0)))
// 			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));
//
// 		stat(newpath, &s);
// 		if (!begin || !dp || !newpath)
// 			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
//
// 		if (!(new = create_entry((*begin) ? (*begin)->length : 0, &s, dp, newpath)))
// 			return (pft_error(ctx->exec_name, "", MALLOC_FAILED, NULL));
//
//
// 		/* REVERSE */
// 		// puts("standard");
// 		if (push_sort_entry(begin, &new, &compare_lex_standard) == NULL)
// 			return (pft_error(ctx->exec_name, "", UNKNOWN_ERROR, NULL));
// 		/* RECURSIVE */
// 		if ((ctx->options & OPT_RECURSIVE) && (dp->d_namlen > 2 || !is_dot_double_dot(new->name)) && (new->mode & MODE_IS_NODE))
// 		{
// 			// printf("A------>%p\n", *begin);
// 			// printf("RECURSIVE:%s\n", newpath);
// 			make_entries(ctx, &new->node, newpath);
// 			// make_node_entry(ctx, &new->node, newpath, 1);
// 			// printf("B------>%p\n", *begin);
// 		}
// 		free((void*)newpath);
//
// 	}
// 	(void)closedir(dirp);
// 	return (*begin);
// }
