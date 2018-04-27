#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "mystdint.h"
#include "error.h"

static int	format_line(t_entry *entry, char **line)
{
	t_u64 const	nlinks_len = ft_numberlen(entry->begin->entry_long->biggest_nlink, 10);
	t_u64 const	size_len = ft_numberlen(entry->begin->entry_long->biggest_size, 10);
	t_u64 const user_len = ft_strlen(entry->entry_long->username);
	t_u64 const grp_len = ft_strlen(entry->entry_long->grp_name);

	if (!(*line = (char*)my_calloc(33 + nlinks_len + size_len + user_len + grp_len + ft_strlen(entry->name))))
		return (ft_error("", "format_line()", MALLOC_FAILED, 1));
	ft_strncpy(*line, entry->entry_long->rights, 10);
	ft_strcat(*line, "  ");
	ft_strcat(*line, "B"); // nlink
	ft_strcat(*line, "  ");
	ft_strcat(*line, entry->entry_long->username);
	ft_strcat(*line, "  ");
	ft_strcat(*line, entry->entry_long->grp_name);
	ft_strcat(*line, "  ");
	ft_strcat(*line, "B"); // size
	ft_strcat(*line, " ");
	ft_strcat(*line, entry->entry_long->date);
	ft_strcat(*line, " ");
	ft_strcat(*line, entry->name);
	return (0);
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
			if (format_line(tmp, &line))
				return (1);
			ft_puts(line);
			free(line);
			next = tmp->next;
			tmp = next;
		}
	}
	return (0);
}
