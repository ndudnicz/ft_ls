#include <stdlib.h>

#include "entry.h"
#include "mystdint.h"


#include <stdio.h>//
static t_entry	*insert_between(
	t_entry **begin,
	t_entry **prev,
	t_entry **new,
	t_entry **next
)
{
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
		(*new)->next = *next;
		(*next)->prev = *new;
	}
	return (*new);
}
#include "display.h"//
t_entry		*push_sort_entry(
	t_entry **begin,
	t_entry **new,
	t_s32	(*compare)(t_entry*, t_entry*)
)
{
	t_entry		*tmp;
	int			cmp;

	tmp = *begin;
	if (*new == NULL)
	{
		return (NULL);
	}
	else if (*begin == NULL)
	{
			*begin = *new;
			(*new)->last = *new;
		return (*new);
	}
	else
	{
		while (tmp)
		{
			cmp = compare(*new, tmp);

			if (cmp < 0)
			{
				insert_between(begin, &tmp->prev, new, &tmp);
				return (*new);
			}
			else
			{
				tmp = tmp->next;
			}
		}
		push_back_entry(begin, new);
	}
	return (*begin);
}
