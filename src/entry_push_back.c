#include <stdlib.h>

#include "entry.h"

/*
** Push back the new entry at the end of the entry list
*/
t_entry		*push_back_entry(
	t_entry **begin,
	t_entry **new
)
{
	// printf("push_back: %s\n\n", (*new)->name); //
	if (*new == NULL)
		return (NULL);
	if (*begin == NULL)
	{
		*begin = *new;
	}
	if ((*begin)->last)
	{
		(*new)->prev = (*begin)->last;
		(*begin)->last->next = *new;
	}
	(*begin)->last = *new;
	return (*begin);
}
