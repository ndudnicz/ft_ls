#include <time.h>
#include <stdlib.h>//
#include <grp.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"

/*
** Init the new entry
*/
t_entry		*init_entry(
	t_entry *new,
	t_u64 const length,
	struct stat *s,
	t_u8 const name_len
)
{
	new->length = length + 1;
	new->mode |= S_ISDIR(s->st_mode) ? MODE_IS_NODE : 0;
	new->mode |= S_ISLNK(s->st_mode) ? MODE_IS_SYM : 0;
	ft_memcpy((void*)&new->stat, (void*)s, sizeof(struct stat));
	new->name_len = name_len;
	return (new);
}

t_entry		*init_long_entry(
	t_entry *new,
	t_u64 const length,
	struct stat *s,
	t_u8 const name_len
)
{
	char const *const str = ctime(&s->st_atime);
	struct group const *g = getgrgid(s->st_gid);

	init_entry(new, length, s, name_len);
	new->entry_long->date = ft_strndup(str + 4, 12);
	new->entry_long->grp_name = ft_strdup(g->gr_name);

	// free(g);
	// printf("%s\n", new->entry_long->grp_name);

	return (new);
}
