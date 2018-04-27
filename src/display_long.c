#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "mystdint.h"

static char	*format_line(t_entry *entry)
{
	
}

int			display_root_entries_long(
	t_u8 const options,
	t_entry *begin
)
{
	t_entry		*tmp;
	t_entry		*next;
	char		*line;

	line = NULL;
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
			line = format_line(tmp);
			ft_puts(line);
			free(line);
			next = tmp->next;
			tmp = next;
		}
	}
	return (0);
}
