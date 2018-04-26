#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "mystdint.h"

int			display_root_entries(
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
			tmp = next;
		}
		else
		{
			ft_puts(tmp->name);
			next = tmp->next;
			tmp = next;
		}
	}
	return (0);
}
