#ifndef OPTIONS_H
# define OPTIONS_H

# define OPT_LONG_FORMAT		0x01
# define OPT_RECURSIVE			0x02
# define OPT_DOT_FILES			0x04
# define OPT_REVERSE			0x08
# define OPT_SORT_TIME			0x10

# define OPT_LONG_FORMAT_CHAR	'l'
# define OPT_RECURSIVE_CHAR		'R'
# define OPT_DOT_FILES_CHAR		'a'
# define OPT_REVERSE_CHAR		'r'
# define OPT_SORT_TIME_CHAR		't'

# define PARAMS_STR				"lRart"

# include "mystdint.h"

typedef struct		s_context
{
	char			*exec_name;
	t_u8			options;
}					t_context;

int		get_options(
	t_context *ctx,
	int *ac,
	char **av
);

#endif
