#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"

#include <stdio.h>//

int		display_root_entries(
	t_context *ctx,
	t_entry **begin
	// char const * const rootname,
	// char const is_in_node
)
{
	t_entry		*tmp;
	// int i = 0;

	tmp = *begin;
	while (tmp)
	{
		if (!(ctx->options & OPT_DOT_FILES) && tmp->name && tmp->name[0] == '.')
			tmp = tmp->next;
		else
		{
			// printf("%d->%s %s\n",i, tmp->name, tmp->next ? tmp->next->name : tmp->name);
			// printf("%p %s\n", tmp, tmp->name);

			// i++;
			ft_puts(tmp->name);
			// printf("%s\n", tmp->name);
			tmp = tmp->next;
		}
	}
	return (0);
}


// int		display_entries_debug(
// 	t_context *ctx,
// 	t_entry **begin,
// 	char const is_in_node
// )
// {
// 	return (0);
// }

int		display_entries(
	t_context *ctx,
	t_entry **begin,
	char const is_in_node
)
{
	t_entry		*tmp;

	tmp = *begin;
	// printf("%p\n", *begin);
	if (!is_in_node)
		display_root_entries(ctx, begin);
	while (tmp)
	{
		if ((ctx->options & OPT_RECURSIVE) && (tmp->mode & MODE_IS_NODE))
		{
			ft_putstr(tmp->fullname);
			ft_puts(":\n");
			// printf("%s:\n", tmp->fullname);
			display_root_entries(ctx, &tmp->node);
			display_entries(ctx, &tmp->node, 1);
		}
		tmp = tmp->next;
	}
	return (0);
}
