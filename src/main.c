#include <stdlib.h>

#include "options.h"
#include "libftasm.h"//
#include "entry.h"
#include "display.h"
#include "libft.h"//
#include "free.h"


int		main(int ac, char **av)
{
	t_context	ctx;

	ft_memset((void*)&ctx, 0, sizeof(t_context));
	if (get_options(&ctx, &ac, av))
		return (EXIT_FAILURE);
	ctx.exec_name = av[0];
	make_entries(&ctx, NULL, ac > 1 && av[1] ? av[1] : ".");
	return (0);
}
