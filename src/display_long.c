/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:16 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:18 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "mystdint.h"
#include "error.h"

static void	put_space(char *s, t_u64 len)
{
	while (len > 0)
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

static int	format_line_norme(
	t_entry *entry,
	char **line
)
{
	static_itoa(*line + ft_strlen(*line) +
	ft_numberlen(entry->lstat.st_nlink, 10) - 1, entry->lstat.st_nlink);
	ft_strcat(*line, " ");
	ft_strcat(*line, entry->entry_long->username);
	ft_strcat(*line, "  ");
	put_space(*line, entry->data->entry_long->sizes.biggest_usr_len -
	ft_strlen(entry->entry_long->username));
	ft_strcat(*line, entry->entry_long->grp_name);
	put_space(*line, entry->data->entry_long->sizes.biggest_grp_len -
	ft_strlen(entry->entry_long->grp_name));
	ft_strcat(*line, "  ");
	put_space(*line, entry->data->entry_long->sizes.biggest_size_len -
	ft_numberlen(entry->lstat.st_size, 10));
	static_itoa(*line + ft_strlen(*line) +
	ft_numberlen(entry->lstat.st_size, 10) - 1, entry->lstat.st_size);
	ft_strcat(*line, " ");
	ft_strcat(*line, entry->entry_long->date);
	ft_strcat(*line, " ");
	ft_strcat(*line, entry->name);
	return (0);
}

static int	format_line(
	t_entry *entry,
	char **line
)
{
	if (!(*line = (char*)my_calloc(34 +
		entry->data->entry_long->sizes.biggest_nlink_len +
		entry->data->entry_long->sizes.biggest_size_len +
		entry->data->entry_long->sizes.biggest_grp_len +
		entry->data->entry_long->sizes.biggest_usr_len +
		ft_strlen(entry->name) +
		(entry->mode & MODE_IS_SYM ? 4 +
		ft_strlen(entry->entry_long->sym_name) : 0))))
		return (ft_error("", "format_line()", MALLOC_FAILED, 1));
	ft_strncpy(*line, entry->entry_long->rights, 10);
	ft_strcat(*line, "  ");
	put_space(*line, entry->data->entry_long->sizes.biggest_nlink_len -
	ft_numberlen(entry->lstat.st_nlink, 10));
	format_line_norme(entry, line);
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
