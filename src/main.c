#include <dirent.h>
#include <stdlib.h>

#include "options.h"
#include "libftasm.h"
#include "entry.h"



int		main(int ac, char **av)
{
	t_context	ctx;

	ft_memset((void*)&ctx, 0, sizeof(t_context));
	if (get_options(&ctx, &ac, av))
		return (EXIT_FAILURE);

	t_entry		*begin = NULL;
	t_entry		*new = NULL;
	DIR		*dirp = opendir(".");
	struct stat 	s;
	struct dirent	*dp = NULL;
	while ((dp = readdir(dirp)) != NULL) {
		stat(dp->d_name, &s);
		new = create_entry(begin ? begin->length : 0, &s, dp);
		push_bach_entry(&begin, &new);
		// printf("%s\n", begin->name);
		printf("%s\n", begin->last->name);
	}
	(void)closedir(dirp);

	return (0);
}
