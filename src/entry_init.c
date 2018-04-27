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
	struct stat s[2],
	t_u8 const name_len
)
{
	new->length = length + 1;
	new->mode |= S_ISDIR(s[0].st_mode) ? MODE_IS_NODE : 0;
	new->mode |= S_ISLNK(s[1].st_mode) ? MODE_IS_SYM : 0;
	ft_memcpy((void*)&new->stat, (void*)&s[0], sizeof(struct stat));
	ft_memcpy((void*)&new->lstat, (void*)&s[1], sizeof(struct stat));
	new->name_len = name_len;
	return (new);
}

/*
** Init the new entry, -l long format edition
*/
t_entry		*init_long_entry(
	t_entry *new,
	t_u64 const length,
	struct stat s[2],
	t_u8 const name_len
)
{
	char const *const str = ctime(&(s[0].st_atime));
	struct group const *g = getgrgid(s[0].st_gid);

	init_entry(new, length, s, name_len);
	new->entry_long->date = ft_strndup(str + 4, 12);
	new->entry_long->grp_name = ft_strdup(g->gr_name);
	return (new);
}
