/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:13 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:14 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entry.h"
#include "libftasm.h"
#include "mystdint.h"
#include "options.h"

int		display_root_entries(
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
