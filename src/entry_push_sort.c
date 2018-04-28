#include <stdlib.h>

#include "entry.h"
#include "mystdint.h"
#include "libftasm.h"

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
		(*next)->prev = *new;
		(*new)->next = *next;
		// if ((*new)->entry_long)
			// ft_memcpy(&(*new)->entry_long->sizes, &(*next)->entry_long->sizes, sizeof(t_sizes));
	}

	return (*new);
}

static t_entry	*push_sort_entry_norme(
	t_entry **begin,
	t_entry **new,
	t_s32	(*compare)(t_entry*, t_entry*)
)
{
	t_entry		*tmp;
	int			cmp;

	tmp = *begin;
	while (tmp)
	{
		cmp = compare(*new, tmp);
		if (cmp < 0)
		{
			return (insert_between(begin, &tmp->prev, new, &tmp));
		}
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

t_entry		*push_sort_entry(
	t_entry **begin,
	t_entry **new,
	t_s32	(*compare)(t_entry*, t_entry*)
)
{
	if (*begin == NULL)
	{
		*begin = *new;
		(*new)->last = *new;
		return (*new);
	}
	else
		return (push_sort_entry_norme(begin, new, compare));
}
