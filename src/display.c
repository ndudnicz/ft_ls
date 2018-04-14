#include "entry.h"
#include "libftasm.h"
#include "libft.h"

void	display_entries(
	t_context *ctx,
	t_entry *begin
)
{
	while (begin)
	{
		if (!(ctx->options & OPT_DOT_FILES) && begin->name[0] == '.')
		{
			begin = begin->next;
			continue ;
		}
		else
		{
			ft_putendl(begin->name);
			begin = begin->next;
		}
	}
}

void	display_entries_debug(
	t_context *ctx,
	t_entry **begin
)
{
	t_entry *tmp = *begin;

	while (tmp)
	{
		if (!(ctx->options & OPT_DOT_FILES) && tmp->name[0] == '.')
		{
			tmp = tmp->next;
			continue ;
		}
		else
		{
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
}
