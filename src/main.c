#include "options.h"
#include "libftasm.h"
#include "stdlib.h"

int		main(int ac, char **av)
{
	t_context	ctx;

	ft_memset((void*)&ctx, 0, sizeof(t_context));
	if (get_options(&ctx, &ac, av))
		return (EXIT_FAILURE);
	printf("%02x\n", ctx.options);
	return (0);
}
