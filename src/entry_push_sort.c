#include <stdlib.h>

#include "entry.h"
#include "mystdint.h"


#include <stdio.h>//
static t_entry	*insert_between(
	t_entry **prev,
	t_entry **new,
	t_entry **next
)
{
	// puts((*new)->name);
	if (*prev)
	{
		// puts("prev");
		(*prev)->next = *new;
		(*new)->prev = *prev;
	}
	if (*next)
	{
		// puts("next");
		(*new)->next = *next;
		(*next)->prev = *new;
	}
	return (*new);
	// puts("----------");
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
		return (NULL);
	else if (*begin == NULL)
	{
		*begin = *new;
	}
	// else if (compare(*new, *begin) < 0)
	// {
	// 	(*new)->next = *begin;
	// 	*begin = *new;
	// }
	else
	{
		while (tmp)
		{
			cmp = compare(*new, tmp);

			if (cmp <= 0)
			{
				return (insert_between(&tmp->prev, new, &tmp));
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
