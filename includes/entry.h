#ifndef ENTRY_H
# define ENTRY_H

# include <sys/stat.h>
#include <dirent.h>

# include "mystdint.h"

# define	MODE_IS_NODE	0x01

typedef struct		s_entry
{
	struct stat		stat;
	char			*name;
	struct s_entry	*next;
	struct s_entry	*prev;
	struct s_entry	*last;
	struct s_entry	*node;
	t_u64			length;
	char			mode;
}					t_entry;

t_entry		*create_entry(t_u64 const length,
							struct stat *s, struct dirent *dir);
t_entry		*push_back_entry(t_entry **begin, t_entry **new);

#endif
