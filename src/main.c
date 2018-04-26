#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"
#include "display.h"
#include "compare.h"
#include "options.h"
#include "entry_parse.h"
#include "entry_parse_long.h"

static t_s32	usage(t_s32 const ret)
{
	ft_puts("usage: ./ft_ls [-Rrlta] [file ...]");
	return (ret);
}

static void		init_sort_ptr(t_context *ctx)
{
	ctx->sort_ptr[0] = compare_lex_standard;
	ctx->sort_ptr[1] = compare_lex_reverse;
	ctx->sort_ptr[2] = compare_time_modified;
	ctx->sort_ptr[3] = compare_time_modified_reverse;
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
	init_sort_ptr(&ctx);
	switch_make_entries(&ctx, ac > 1 && av[1] ? av[1] : ".");
	return (0);
}
