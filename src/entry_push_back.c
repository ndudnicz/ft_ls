#include <stdlib.h>

#include "entry.h"

/*
** Push back the new entry at the end of the entry list
*/
t_entry		*push_back_entry(
	t_entry **begin,
	t_entry **new,
	t_entry **last
)
{
	if (*begin == NULL)
	{
		*begin = *new;
		(*new)->last = *new;
	}
	else
	{
		(*new)->prev = *last;
		(*last)->next = *new;
		(*begin)->last = *new;
	}
	return (*begin);
}
