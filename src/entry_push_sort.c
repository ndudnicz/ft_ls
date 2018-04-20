#include <stdlib.h>

#include "entry.h"
#include "mystdint.h"

#include "debug.h"//
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
		(*next)->prev = *new;
		(*new)->next = *next;
	}

	return (*new);
}

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
			// printf("sorting: %s\n", tmp->name);
			cmp = compare(*new, tmp);
			if (cmp < 0)
			{
				// printf("insert: %s\n", tmp->name);
				// if (!tmp->prev)
				// {
				// 	*begin = *new;
				// }
				// else
				// {
				// 	tmp->prev->next = *new;
				// 	(*new)->prev = tmp->prev;
				// }
				// tmp->prev = *new;
				// (*new)->next = tmp;
				// printf("%s\n", tmp->name);
				return (insert_between(begin, &tmp->prev, new, &tmp));
				// display_list(*begin);
				// insert_between(begin, &tmp->prev, new, &tmp);

				return (*begin);
			}
			else
			{
				tmp = tmp->next;
			}
		}
		// printf("pushback: %s\n", (*new)->name);
		push_back_entry(begin, new);
			// display_list(*begin);
	}
	return (*begin);
}
