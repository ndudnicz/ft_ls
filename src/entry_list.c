#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "error.h"

/*
** Init the new entry
*/
// char *
// ftstrdup(const char *str)
// {
// 	size_t len;
// 	char *copy;
//
// 	len = strlen(str) + 1;
// 	if ((copy = malloc(len)) == NULL)
// 		return (NULL);
// 	memcpy(copy, str, len);
// 	return (copy);
// }
static t_entry		*init_entry(
	t_entry *new,
	t_u64 const length,
	struct stat *s
)
{
	new->length = length + 1;
	new->mode |= S_ISDIR(s->st_mode) ? MODE_IS_NODE : 0;
	ft_memcpy((void*)&new->stat, (void*)s, sizeof(struct stat));
	return (new);
}

static t_entry		*set_names(
	t_entry *new,
	char const *name,
	char const *fullname
)
{
	printf("%s\n",name);//
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
		!fullname || !dir || !dir->d_name || !s ||
		!(new = new_entry()) ||
		!init_entry(new, length, s) ||
		!set_names(new, dir->d_name, fullname)
	)
		return (pft_error("Error", "create_entry()", MALLOC_FAILED, NULL));
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
	if (*new == NULL)
		return (NULL);
	if (*begin == NULL)
	{
		*begin = *new;
		(*begin)->last = *new;
	}
	(*begin)->last = *new;
	(*begin)->last->next = *new;
	return (*begin);
}
