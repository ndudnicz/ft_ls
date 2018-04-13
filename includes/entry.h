#ifndef ENTRY_H
# define ENTRY_H

# include <sys/stat.h>
#include <dirent.h>

# include "mystdint.h"
# include "options.h"

# define	CUR_DIR_STR		"."
# define	PARENT_DIR_STR	".."

# define	MODE_IS_NODE	0x01

typedef struct		s_entry
{
	struct stat		stat;
	char			*name; // malloc
	char			*fullname; // malloc
	struct s_entry	*next;
	struct s_entry	*prev;
	struct s_entry	*last;
	struct s_entry	*node;
	t_u64			length;
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
	t_entry **new
);

/*
** entry_list.c
*/
t_entry		*create_entry(
	t_u64 const length,
	struct stat *s,
	struct dirent *dir,
	char const * const fullname
);

/*
** entry_parse.c
*/
t_entry		*make_node_entry(
	t_context const *ctx,
	t_entry **begin,
	char const * const path
);

#endif
