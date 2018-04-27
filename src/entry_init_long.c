#include <time.h>
#include <stdlib.h>//
#include <grp.h>
#include <unistd.h>

#include "entry.h"
#include "libftasm.h"
#include "libft.h"
#include "error.h"
#include "entry_init.h"

static void	get_right(t_u8 const r, char *s)
{
	// printf("%o\n", r);
	if (r & 1)
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
	get_right((new->lstat.st_mode & 07), new->entry_long->rights + 7);
	get_right((new->lstat.st_mode & 070) >> 3, new->entry_long->rights + 4);
	get_right((new->lstat.st_mode & 0700) >> 6, new->entry_long->rights + 1);
	// printf("%s %s\n", new->entry_long->rights, new->name);
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
	char const *const str = ctime(&(s[0].st_atime));
	struct group const *g = getgrgid(s[0].st_gid);

	init_entry(begin, new, s);
	new->entry_long->date = ft_strndup(str + 4, 12);
	new->entry_long->grp_name = ft_strdup(g->gr_name);
	if (*begin)
	{
		if (s[1].st_nlink > (*begin)->entry_long->biggest_nlink)
			(*begin)->entry_long->biggest_nlink = s[1].st_nlink;
		if (s[1].st_size > (*begin)->entry_long->biggest_size)
			(*begin)->entry_long->biggest_size = s[1].st_size;
	}
	make_rights(new);
	if ((new->mode & MODE_IS_SYM) &&
	!readlink(new->fullname, new->entry_long->sym_name, __DARWIN_MAXNAMLEN))
		return (pft_perror("", "", NULL));
	else
		return (new);
}
