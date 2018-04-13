#include <stdlib.h>

#include "options.h"
#include "libftasm.h"//
#include "entry.h"
#include "display.h"
#include "libft.h"//


int		main(int ac, char **av)
{
	t_context	ctx;
	t_entry		*begin;

	begin = NULL;
	ft_memset((void*)&ctx, 0, sizeof(t_context));
	if (get_options(&ctx, &ac, av))
		return (EXIT_FAILURE);
	ctx.exec_name = av[0];
	make_node_entry(&ctx, &begin, ac > 1 && av[1] ? av[1] : ".");

	display_entries(begin);
	return (0);
}
