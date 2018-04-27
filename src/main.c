#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "display.h"
#include "compare.h"
#include "options.h"
#include "entry_parse.h"
#include "entry_parse_long.h"
#include "error.h"

static t_s32	usage(t_s32 const ret)
{
	ft_puts("usage: ./ft_ls [-Rrlta] [file ...]");
	return (ret);
}

static t_s32	init_sort_ptr(t_context *ctx)
{
	if ((ctx->options & SORT_MASK) == 0)
	{
		ctx->sort_ptr = &compare_lex_standard;
		return (EXIT_SUCCESS);
	}
	else if ((ctx->options & SORT_MASK) == OPT_REVERSE)
	{
		ctx->sort_ptr = &compare_lex_reverse;
		return (EXIT_SUCCESS);
	}
	else if ((ctx->options & SORT_MASK) == OPT_SORT_TIME)
	{
		ctx->sort_ptr = &compare_time_modified;
		return (EXIT_SUCCESS);
	}
	else if ((ctx->options & SORT_MASK) == OPT_REVERSE + OPT_SORT_TIME)
	{
		ctx->sort_ptr = &compare_time_modified_reverse;
		return (EXIT_SUCCESS);
	}
	else
		return (ft_error(ctx->exec_name, "init_sort_ptr()",
		UNKNOWN_ERROR, EXIT_FAILURE));

}

static t_entry	*switch_make_entries(
	t_context *ctx,
	char *path
)
{
	if (ctx->options & OPT_RECURSIVE)
	{
		if (ctx->options & OPT_LONG_FORMAT)
			return (make_entries_recursive_long(ctx, NULL, path));
		else
			return (make_entries_recursive(ctx, NULL, path));
	}
	else
	{
		if (ctx->options & OPT_LONG_FORMAT)
			return (make_entries_long(ctx, NULL, path));
		else
			return (make_entries(ctx, NULL, path));
	}
}

int				main(int ac, char **av)
{
	t_context	ctx;

	ft_memset((void*)&ctx, 0, sizeof(t_context));
	if (get_options(&ctx, &ac, av))
		return (usage(EXIT_FAILURE));
	ctx.exec_name = av[0];
	if (init_sort_ptr(&ctx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	switch_make_entries(&ctx, ac > 1 && av[1] ? av[1] : ".");
	return (EXIT_SUCCESS);
}
