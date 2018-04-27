#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "mystdint.h"
#include "entry_init.h"
#include "misc.h"

/*
** Create a new entry, init it and return it
*/
t_entry				*create_entry(
	t_entry **begin,
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
)
{
	t_entry		*new;

	new = NULL;
	if (
		!fullname || !dir || !(new = (t_entry*)my_calloc(sizeof(t_entry))) ||
		!init_entry(begin, new, s) ||
		!set_names(new, dir->d_name, fullname)
	)
		return (pft_error("Error", "create_entry()", MALLOC_FAILED, NULL));
	else
		return (new);
}
