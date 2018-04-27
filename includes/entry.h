#ifndef ENTRY_H
# define ENTRY_H

# include <sys/stat.h>
#include <dirent.h>

# include "mystdint.h"

# define	MODE_IS_NODE	0x01
# define	MODE_IS_SYM		0x02

typedef struct		s_entry_long
{
	char	*date; // malloc
	char	*username; // malloc ?
	char	*grp_name; // malloc ?
	char	*sym_name; // malloc ?
}					t_entry_long;

typedef struct		s_entry
{
	struct stat		stat;
	struct stat		lstat;
	struct s_entry	*next;
	struct s_entry	*prev;
	struct s_entry	*last;
	struct s_entry	*node;
	t_entry_long	*entry_long; // malloc
	char			*name; // malloc
	char			*fullname; // malloc
	t_u64			length;
	t_u8			name_len;
	char			mode;
}					t_entry;

#endif
