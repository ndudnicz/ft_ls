#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "mystdint.h"

// #include <stdio.h>//

// __attribute__((always_inline)) static void	free_entry(t_entry **entry)
// {
// 	free((*entry)->name);
// 	// (*entry)->name = NULL;
// 	free((*entry)->fullname);
// 	// (*entry)->fullname = NULL;
// 	// free(*entry);
// 	// *entry = NULL;
// }

int									display_root_entries(
	t_u8 const options,
	t_entry *begin
)
{
	t_entry		*tmp;
	t_entry		*next;

	tmp = begin;
	while (tmp)
	{
		if (!(options & OPT_DOT_FILES) && tmp->name && tmp->name[0] == '.')
		{
			next = tmp->next;
			// free_entry(&tmp);
			tmp = next;
		}
		else
		{
	// puts("b");
			ft_puts(tmp->name);
			next = tmp->next;
			// free_entry(&tmp);
			tmp = next;
	// puts("a");
		}
	}
	return (0);
}

int				display_entries(
	t_context *ctx,
	t_entry *begin,
	char const is_in_node
)
{
	t_entry		*tmp;
	t_entry		*next;

	tmp = begin;
	if (!is_in_node)
		display_root_entries(ctx->options, begin);
	while (tmp)
	{
		if ((ctx->options & OPT_RECURSIVE) && (tmp->mode & MODE_IS_NODE))
		{
			ft_putstr(tmp->fullname);
			ft_puts(":\n");
			display_root_entries(ctx->options, tmp->node);
			display_entries(ctx, tmp->node, 1);
		}
		next = tmp->next;
		// free_entry(&tmp);
		tmp = next;
	}
	return (0);
}
