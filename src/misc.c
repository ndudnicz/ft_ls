/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:40:21 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:40:27 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "entry.h"

int		is_dot_double_dot(char const *const filename)
{
	return (!ft_strcmp(filename, CUR_DIR_STR) ||
			!ft_strcmp(filename, PARENT_DIR_STR));
}

void	*my_calloc(t_u64 const size)
{
	return (ft_memset(malloc(size), 0, size));
}

/*
** Dup names values in entry structure
*/

t_entry	*set_names(
	t_entry *new,
	char const *const name,
	char const *const fullname
)
{
	if (!new || !name || !fullname || !(new->name = ft_strdup(name)) ||
	!(new->fullname = ft_strdup(fullname)))
		return (NULL);
	else
		return (new);
}

void	ft_putuint64(t_u64 n)
{
	if (n >= 10)
	{
		ft_putuint64(n / 10);
		ft_putuint64(n % 10);
	}
	else
		ft_putchar((t_s32)n + 48);
}

void	print_3_strings(
	char const *const s1,
	char const *const s2,
	char const *const s3
)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
}
