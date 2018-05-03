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
#include <sys/types.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "misc.h"
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

static int	format_line_norme_set_major_minor(
	t_entry *entry,
	char **line
)
{
	put_space(*line, entry->data->entry_long->sizes.biggest_major_len -
	ft_numberlen(major(entry->lstat.st_rdev), 10));
	static_itoa(*line + ft_strlen(*line) +
	ft_numberlen(major(entry->lstat.st_rdev), 10) - 1,
	major(entry->lstat.st_rdev));
	ft_strcat(*line, ", ");
	put_space(*line, entry->data->entry_long->sizes.biggest_major_len -
	ft_numberlen(minor(entry->lstat.st_rdev), 10));
	static_itoa(*line + ft_strlen(*line) +
	ft_numberlen(minor(entry->lstat.st_rdev), 10) - 1,
	minor(entry->lstat.st_rdev));
	return (0);
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
	if (!(entry->mode & MODE_SPEC_MASK))
	{
		put_space(*line, entry->data->entry_long->sizes.biggest_size_len -
		ft_numberlen(entry->lstat.st_size, 10));
		static_itoa(*line + ft_strlen(*line) +
		ft_numberlen(entry->lstat.st_size, 10) - 1, entry->lstat.st_size);
	}
	else
		(void)format_line_norme_set_major_minor(entry, line);
	ft_strcat(*line, " ");
	ft_strcat(*line, entry->entry_long->date);
	ft_strcat(*line, " ");
	ft_strcat(*line, entry->name);
	return (0);
}

int			format_line(
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
