#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "mystdint.h"
#include "entry_init.h"
#include "misc.h"

/*
** Dup names values in entry structure
*/
static t_entry		*set_names(
	t_entry *new,
	char const *const name,
	char const *const fullname
)
{
	if (!new || !name || !fullname || !(new->name = ft_strdup(name)) ||
	!(new->fullname = ft_strdup(fullname)))
		return (NULL);
	else
		return (new);
}

/*
** Create a new entry, init it and return it
*/
t_entry				*create_entry(
	t_u64 const length,
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
)
{
	t_entry		*new;

	new = NULL;
	if (
		!fullname || !dir || !(new = (t_entry*)my_calloc(sizeof(t_entry))) ||
		!init_entry(new, length, s, dir->d_namlen) ||
		!set_names(new, dir->d_name, fullname)
	)
		return (pft_error("Error", "create_entry()", MALLOC_FAILED, NULL));
	else
		return (new);
}

/*
** Create a new entry, init it and return it, -l -l -l -l
*/
t_entry				*create_long_entry(
	t_u64 const length,
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
)
{
	t_entry		*new;
	t_u64 const	size = sizeof(t_entry_long);

	new = NULL;
	if (
		!fullname || !dir || !(new = (t_entry*)my_calloc(sizeof(t_entry))) ||
		!set_names(new, dir->d_name, fullname) ||
		!(new->entry_long = (t_entry_long*)my_calloc(size)) ||
		!init_long_entry(new, length, s, dir->d_namlen)
	)
		return (pft_error("Error", "create_entry()", MALLOC_FAILED, NULL));
	else
		return (new);
}
