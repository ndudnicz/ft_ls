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
		// ft_putendl(tmp->name);
		printf("%d: %s \n", tmp->mode & MODE_IS_NODE, tmp->name);
		// if (tmp->mode & MODE_IS_NODE && tmp->node)
			// display_entries_debug(&tmp->node);
		tmp = tmp->next;
	}
}
