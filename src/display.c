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
