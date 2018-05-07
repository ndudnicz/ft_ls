/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_push_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:40:01 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:40:02 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "entry.h"
#include "mystdint.h"
#include "libftasm.h"

static t_entry	*insert_between(
	register t_entry **begin,
	register t_entry **prev,
	register t_entry **new,
	register t_entry **next
)
{
	if (*begin)
	{
		(*new)->data = (*begin)->data;
	}
	if (*prev)
	{
		(*prev)->next = *new;
		(*new)->prev = *prev;
	}
	else
	{
		*begin = *new;
	}
	if (*next)
	{
		(*next)->prev = *new;
		(*new)->next = *next;
	}
	return (*new);
}

static t_entry	*push_sort_entry_norme(
	register t_entry **begin,
	register t_entry **new,
	t_s32 (*compare)(t_entry*, t_entry*)
)
{
	t_entry		*tmp;

	tmp = *begin;
	while (tmp)
	{
		if (compare(*new, tmp) < 0)
			return (insert_between(begin, &tmp->prev, new, &tmp));
		else
		{
			if (tmp->next)
				tmp = tmp->next;
			else
			{
				(*new)->prev = tmp;
				tmp->next = *new;
				(*begin)->last = *new;
				return (*begin);
			}
		}
	}
	return (*begin);
}

t_entry			*push_sort_entry(
	t_entry **begin,
	t_entry **new,
	t_s32 (*compare)(t_entry*, t_entry*)
)
{
	if (*begin == NULL)
	{
		*begin = *new;
		(*new)->last = *new;
		(*begin)->data = *new;
		return (*new);
	}
	else
		return (push_sort_entry_norme(begin, new, compare));
}
