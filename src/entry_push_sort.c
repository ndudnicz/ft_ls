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
	char *bb = (*begin) ? (*begin)->name : "null";
	char *pp = (*prev) ? (*prev)->name : "null";
	char *nnn = (*new) ? (*new)->name : "null";
	char *nnnn = (*next) ? (*next)->name : "null";
	puts(bb);
	puts(pp);
	puts(nnn);
	puts(nnnn);
	// printf("%s, %s, %s, %s\n", bb, pp, nnn, nnnn);

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
	char *b = (*begin) ? (*begin)->name : "null";
	char *p = (*prev) ? (*prev)->name : "null";
	char *n = (*new) ? (*new)->name : "null";
	char *nn = (*next) ? (*next)->name : "null";
	puts(b);
	puts(p);
	puts(n);
	puts(nn);
	// printf("%s, %s, %s, %s\n", b, p, n, nn);

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
				printf("insert: %s\n", tmp->name);
				if (!tmp->prev)
				{
					*begin = *new;
				}
				else
				{
					tmp->prev->next = *new;
					(*new)->prev = tmp->prev;
				}
				tmp->prev = *new;
				(*new)->next = tmp;
				printf("%s\n", tmp->name);
				// return (insert_between(begin, &tmp->prev, new, &tmp));
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
