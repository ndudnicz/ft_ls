#include <stdlib.h>

#include "libftasm.h"
#include "libft.h"
#include "misc.h"
#include "entry.h"

int		is_dot_double_dot(char const * const filename)
{
	return (!ft_strcmp(filename, CUR_DIR_STR) ||
			!ft_strcmp(filename, PARENT_DIR_STR));
}

void	*my_calloc(t_u64 const size)
{
	return (ft_memset(malloc(size), 0, size));
}

/*
** Dup names values in entry structure
*/
t_entry	*set_names(
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
