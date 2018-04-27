#ifndef MISC_H
# define MISC_H

# define	CUR_DIR_STR		"."
# define	PARENT_DIR_STR	".."

# include "options.h"
# include "mystdint.h"

typedef struct	s_var_box
{
	t_context			*ctx;
	char				*exec_name;
	t_entry				**begin;
	struct dirent		*dp;
	char 				*path;

}				t_var_box;

int		is_dot_double_dot(char const *const filename);

void	*my_calloc(t_u64 const size);

t_entry	*set_names(
	t_entry *new,
	char const *const name,
	char const *const fullname
);


#endif
