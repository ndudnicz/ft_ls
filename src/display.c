#include "entry.h"
#include "libftasm.h"
#include "libft.h"

void	display_entries(t_entry *begin)
{
	while (begin)
	{
		ft_putendl(begin->name);
		begin = begin->next;
	}
}

void	display_entries_debug(t_entry **begin)
{
	t_entry *tmp = *begin;

	while (tmp)
	{
		ft_putendl(tmp->name);
		tmp = tmp->prev;
	}
}
