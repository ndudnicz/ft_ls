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
	t_entry		*tmp;
	tmp = *begin;
	if (!tmp)
	{
		*begin = *new;
		*last = *new;
	}
	else
	{
		(*last)->next = *new;
		*last = *new;
	}
	return (*begin);
}
