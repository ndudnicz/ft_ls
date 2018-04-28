#include <time.h>
#include <stdlib.h>//
#include <grp.h>
#include <unistd.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"

/*
** Init the new entry
*/
t_entry		*init_entry(
	t_entry **begin,
	t_entry *new,
	struct stat s[2]
)
{
	new->mode |= S_ISDIR(s[0].st_mode) ? MODE_IS_NODE : 0;
	new->mode |= S_ISLNK(s[1].st_mode) ? MODE_IS_SYM : 0;
	ft_memcpy((void*)&new->stat, (void*)&s[0], sizeof(struct stat));
	ft_memcpy((void*)&new->lstat, (void*)&s[1], sizeof(struct stat));
	return (new);
}
