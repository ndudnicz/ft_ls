#include <time.h>
#include <stdlib.h>//
#include <grp.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <sys/types.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "entry_init.h"
#include "options.h"

static void	get_right(
	t_u8 const p,
	t_u8 const r,
	char *s)
{
	if (p)
		s[2] = 's';
	else if (r & 1)
		s[2] = 'x';
	else
		s[2] = '-';
	if (r & 2)
		s[1] = 'w';
	else
		s[1] = '-';
	if (r & 4)
		s[0] = 'r';
	else
		s[0] = '-';
}

static char	get_type(struct stat *s)
{
	if (S_ISBLK(s->st_mode))
		return ('b');
	else if (S_ISCHR(s->st_mode))
		return ('c');
	else if (S_ISDIR(s->st_mode))
		return ('d');
	else if (S_ISFIFO(s->st_mode))
		return ('p');
	else if (S_ISLNK(s->st_mode))
		return ('l');
	else if (S_ISSOCK(s->st_mode))
		return ('s');
	else
		return ('-');
}

static void	make_rights(t_entry *new)
{
	new->entry_long->rights[0] = get_type(&new->lstat);
	get_right(0, (new->lstat.st_mode & 07), new->entry_long->rights + 7);
	get_right(((new->lstat.st_mode & 07000) >> 9) & 2,
	(new->lstat.st_mode & 070) >> 3, new->entry_long->rights + 4);
	get_right(((new->lstat.st_mode & 07000) >> 9) & 4,
	(new->lstat.st_mode & 0700) >> 6, new->entry_long->rights + 1);
}

/*
** Init the new entry, -l long format edition
*/
t_entry		*init_long_entry(
	t_entry **begin,
	t_entry *new,
	struct stat s[2]
)
{
	// printf("", );
	char const *const str = ctime(&(s[1].st_mtime));
	struct group const *g = getgrgid(s[0].st_gid);
	struct passwd const *pw = getpwuid(s[0].st_uid);

	init_entry(begin, new, s);
	if (ft_strstr(str, CURRENT_YEAR))
		ft_memcpy(new->entry_long->date, str + 4, 12);
	else
	{
		ft_memcpy(new->entry_long->date, str + 4, 7);
		ft_memcpy(new->entry_long->date + 7, str + 19, 5);

	}

	new->entry_long->grp_name = ft_strdup(g->gr_name);
	new->entry_long->username = ft_strdup(pw->pw_name);
	make_rights(new);
	if ((new->mode & MODE_IS_SYM) &&
	!readlink(new->fullname, new->entry_long->sym_name, __DARWIN_MAXNAMLEN))
		return (pft_perror("", "", NULL));
	else
		return (new);
}
