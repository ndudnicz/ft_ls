#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"

#include <stdio.h>//

int		display_root_entries(
	t_context *ctx,
	t_entry **begin,
	char const * const rootname,
	char const is_in_node
)
{
	t_entry		*tmp;

	tmp = *begin;
	if (!tmp || !tmp->name || !rootname || (!is_in_node && !is_dot_double_dot(tmp->name)))
		return (0);
	int i = 0;
	if (rootname && tmp)
		printf("\nin_node : %d root: %s, title : %s:\n", is_in_node, tmp->name, rootname);
	while (tmp)
	{
		if (!(ctx->options & OPT_DOT_FILES) && is_dot_double_dot(tmp->name))
		{
			tmp = tmp->next;
			continue ;
		}
		else
		{
			// ft_puts(tmp->name);
			printf("in_node : %d   %d root: %s, root_entry : %s\n", is_in_node, i, (*begin)->name,tmp->name);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}


int		display_entries_debug(
	t_context *ctx,
	t_entry **begin,
	char const is_in_node
)
{
	t_entry *tmp = *begin;

	// display_root_entries(ctx, tmp, , 0);
	while (tmp)
	{
		if (/*start == tmp->name &&*//*tmp && tmp->name && tmp->node && */(ctx->options & OPT_RECURSIVE) && (tmp->mode & MODE_IS_NODE) && !is_dot_double_dot(tmp->name))
		{
			// display_root_entries(ctx, tmp->node, tmp->fullname, 1);
			display_root_entries(ctx, &tmp->node, tmp->fullname, 1);
			display_entries_debug(ctx, &tmp->node, 1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		display_entries(
	t_context *ctx,
	t_entry **begin
)
{
	display_root_entries(ctx, begin, ".", 0);
	display_entries_debug(ctx, begin, 0);

	// while (begin)
	// {
	// 	if (!(ctx->options & OPT_DOT_FILES) && begin->name[0] == '.')
	// 	{
	// 		begin = begin->next;
	// 		continue ;
	// 	}
	// 	else
	// 	{
	// 		// ft_putendl(begin->name);
	// 		begin = begin->next;
	// 	}
	// }
	return (0);
}
