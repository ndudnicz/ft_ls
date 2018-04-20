#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "mystdint.h"

#include <stdio.h>//

int		display_root_entries(
	t_u8 const options,
	t_entry *begin
)
{
	t_entry		*tmp;

	tmp = begin;
	// write(1, "C\n", 2);
	while (tmp)
	{

	// // printf("%c\n", tmp->name[0]);
		if (!(options & OPT_DOT_FILES) && tmp->name && tmp->name[0] == '.')
		{
	// write(1, "C\n", 2);

			tmp = tmp->next;
		}
		else
		{
	// write(1, "B\n", 2);
			ft_puts(tmp->name);
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
	t_entry *begin,
	char const is_in_node
)
{
	t_entry		*tmp;

	tmp = begin;
	// printf("%p\n", *begin);
	if (!is_in_node)
		display_root_entries(ctx->options, begin);
	while (tmp)
	{
		if ((ctx->options & OPT_RECURSIVE) && (tmp->mode & MODE_IS_NODE))
		{
			ft_putstr(tmp->fullname);
			ft_puts(":\n");
			// printf("%s:\n", tmp->fullname);
			display_root_entries(ctx->options, tmp->node);
			display_entries(ctx, tmp->node, 1);
		}
		tmp = tmp->next;
	}
	return (0);
}
