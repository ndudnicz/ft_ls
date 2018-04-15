#include "libftasm.h"
#include "misc.h"

int		is_dot_double_dot(char const * const filename)
{
	return (!ft_strcmp(filename, CUR_DIR_STR) ||
			!ft_strcmp(filename, PARENT_DIR_STR));
}
