#include <stdlib.h>

#include "entry.h"
#include "mystdint.h"

static void	insert_between(
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
	if (*next)
	{
		(*new)->next = *next;
		(*next)->prev = *new;
	}
}

t_entry		*push_sort_entry(
	t_entry **begin,
	t_entry **new,
	t_s32	(*compare)(t_entry*, t_entry*)
)
{
	t_entry		*tmp;

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
			if (compare(*new, tmp) < 0)
			{
				insert_between(&tmp->prev, new, &tmp);
				return (*begin);
			}
			tmp = tmp->next;
		}
		push_back_entry(begin, new);
	}
	return (*begin);
}
