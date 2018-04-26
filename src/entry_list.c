#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "mystdint.h"
#include "entry_init.h"

static t_entry		*set_names(
	t_entry *new,
	char const * const name,
	char const * const fullname
)
{
	if (!new || !name || !fullname || !(new->name = ft_strdup(name)) ||
	!(new->fullname = ft_strdup(fullname)))
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
	struct dirent *dir,
	char const *fullname
)
{
	t_entry		*new;

	new = NULL;
	if (
		!fullname || !dir || !s ||
		!(new = new_entry()) ||
		!init_entry(new, length, s, dir->d_namlen) ||
		!set_names(new, dir->d_name, fullname)
	)
		return (pft_error("Error", "create_entry()", MALLOC_FAILED, NULL));
	else
		return (new);
}

t_entry				*create_long_entry(
	t_u64 const length,
	struct stat *s,
	struct dirent *dir,
	char const *fullname
)
{
	t_entry		*new;

	new = NULL;
	if (
		!fullname || !dir || !s ||
		!(new = new_entry()) ||
		!set_names(new, dir->d_name, fullname) ||
		!(new->entry_long = (t_entry_long*)malloc(sizeof(t_entry_long))) ||
		!init_long_entry(new, length, s, dir->d_namlen)
	)
		return (pft_error("Error", "create_entry()", MALLOC_FAILED, NULL));
	else
	{
		// printf("%p\n", new->entry_long);
		return (new);

	}
}
