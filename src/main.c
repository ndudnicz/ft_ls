#include <stdlib.h>

#include "options.h"
#include "libftasm.h"
#include "entry.h"



int		main(int ac, char **av)
{
	t_context	ctx;
	t_entry		*begin;

	begin = NULL;
	ft_memset((void*)&ctx, 0, sizeof(t_context));
	if (get_options(&ctx, &ac, av))
		return (EXIT_FAILURE);
	ctx.exec_name = av[0];
	make_node_entry(&ctx, &begin, av[1]);
	return (0);
}
