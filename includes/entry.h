#ifndef ENTRY_H
# define ENTRY_H

# include <sys/stat.h>
#include <dirent.h>

# include "mystdint.h"
# include "options.h"

# define	MODE_IS_NODE	0x01

typedef struct		s_entry
{
	struct stat		stat;
	struct s_entry	*next;
	struct s_entry	*prev;
	struct s_entry	*last;
	struct s_entry	*node;
	char			*name; // malloc
	char			*fullname; // malloc
	t_u64			length;
	t_u8			name_len;
	char			mode;
}					t_entry;

/*
** entry_push_sort.c
*/
t_entry		*push_sort_entry(
	t_entry **begin,
	t_entry **new,
	t_s32	(*compare)(t_entry*, t_entry*)
);

/*
** entry_push_back.c
*/
t_entry		*push_back_entry(
	t_entry **begin,
	t_entry **new,
	t_entry **last
);

/*
** entry_list.c
*/
t_entry		*create_entry(
	t_u64 const length,
	struct stat *s,
	struct dirent *dir,
	char const *const fullname
);

/*
** entry_parse.c
*/
t_entry		*make_entries(
	t_context *ctx,
	t_entry *begin,
	char const *const path
);
#endif
