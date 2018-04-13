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
	if (*new == NULL)
		return (NULL);
	if (*begin == NULL)
	{
		*begin = *new;
	}
	if ((*begin)->last)
	{
		(*begin)->last->next = *new;
	}
	(*begin)->last = *new;
	return (*begin);
}
