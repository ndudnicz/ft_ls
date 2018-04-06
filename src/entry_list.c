#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "error.h"

/*
** Init the new entry
*/
static t_entry		*init_entry(
	t_entry *new,
	t_u64 const length,
	struct stat *s,
	struct dirent *dir
)
{
	new->length = length + 1;
	new->mode |= S_ISDIR(*s) ? MODE_IS_NODE : 0;
	ft_memcpy((void*)&new->stat, (void*)s, sizeof(struct stat));
	if (!(new->name = ft_strdup(dir->d_name)))
		return (NULL);
	else
		return (new);
}

/*
** Return a fresh 0ed entry
*/
static t_entry		*new_entry(void)
{
	t_u64 const	s = sizeof(t_entry);

	return ((t_entry*)ft_memset((void*)malloc(s), 0, s));
}

/*
** Create a new entry, init it and return it
*/
t_entry				*create_entry(
	t_u64 const length,
	struct stat *s,
	struct dirent *dir
)
{
	t_entry		*new;

	if (!(new = new_entry()) || !init_entry(new, length, s, dir))
	{
		ft_error("Error", "init_entry()", MALLOC_FAILED, 0);
		return (NULL);
	}
	else
		return (new);
}

/*
** Push back the new entry at the end of the entry list
*/
t_entry		*push_back_entry(
	t_entry **begin,
	t_entry **new
)
{
	if (*begin == NULL)
	{
		*begin = *new;
		(*new)->last = *new;
	}
	(*begin)->last->next = *new;
	(*begin)->last = *new;
	return (*begin);
}
