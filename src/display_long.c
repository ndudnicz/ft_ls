#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "mystdint.h"
#include "error.h"

#include <stdio.h>//

static void	put_space(char *s, t_u64 len)
{
	while (len > 1)
	{
		ft_strcat(s, " ");
		len--;
	}
}

static void	static_itoa(
	char *s,
	t_u64 n
)
{
	if (n >= 10)
	{
		static_itoa(s, n % 10);
		static_itoa(s - 1, n / 10);
	}
	else
	{
		*s = n + 48;
	}
}

static int	format_line(
	t_entry *entry,
	char **line
)
{
	t_u64 const user_len = ft_strlen(entry->entry_long->username);
	t_u64 const grp_len = ft_strlen(entry->entry_long->grp_name);

	if (!(*line = (char*)my_calloc(33 + entry->begin->entry_long->sizes.biggest_nlink_len + entry->begin->entry_long->sizes.biggest_size_len + user_len + grp_len + ft_strlen(entry->name) + 1 + (entry->mode & MODE_IS_SYM ? 4 + ft_strlen(entry->entry_long->sym_name) : 0))))
		return (ft_error("", "format_line()", MALLOC_FAILED, 1));
	ft_strncpy(*line, entry->entry_long->rights, 10);
	ft_strcat(*line, "  ");
	put_space(*line, entry->begin->entry_long->sizes.biggest_nlink_len - ft_numberlen(entry->lstat.st_nlink, 10));
	static_itoa(*line + ft_strlen(*line) + ft_numberlen(entry->lstat.st_nlink, 10) - 1, entry->lstat.st_nlink);
	ft_strcat(*line, " "); // 1
	ft_strcat(*line, entry->entry_long->username);
	ft_strcat(*line, "  "); // 2
	ft_strcat(*line, entry->entry_long->grp_name);
	ft_strcat(*line, "  "); // 2
	put_space(*line, entry->begin->entry_long->sizes.biggest_size_len - ft_numberlen(entry->lstat.st_size, 10));
	static_itoa(*line + ft_strlen(*line) + ft_numberlen(entry->lstat.st_size, 10) - 1, entry->lstat.st_size);
	ft_strcat(*line, " "); // 1
	ft_strcat(*line, entry->entry_long->date);
	ft_strcat(*line, " "); // 1
	ft_strcat(*line, entry->name);
	if (entry->mode & MODE_IS_SYM)
	{
		ft_strcat(*line, " -> ");
		ft_strcat(*line, entry->entry_long->sym_name);
	}
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
