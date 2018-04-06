#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "error.h"

static t_entry		*init_entry(
	t_entry *new,
	t_u64 const length,
	struct stat *s,
	struct dirent *dir
)
{
	new->length = length + 1;
	ft_memcpy((void*)&new->stat, (void*)s, sizeof(struct stat));
	if (!(new->name = ft_strdup(dir->d_name)))
		return (NULL);
	else
	{
		// printf("%d: %s\n", new->length, new->name);
		return (new);
	}
}

static t_entry		*new_entry(void)
{
	t_u64 const	s = sizeof(t_entry);

	return ((t_entry*)ft_memset((void*)malloc(s), 0, s));
}

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
