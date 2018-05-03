/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:40:16 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:40:17 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

#include "entry.h"
#include "libftasm.h"
#include "compare.h"
#include "options.h"
#include "error.h"
#include "run.h"

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

int				main(
	int ac,
	char **av
)
{
	t_context	ctx;
	time_t		clock;

	ft_memset((void*)&ctx, 0, sizeof(t_context));
	if (get_options(&ctx, &ac, av))
		return (usage(EXIT_FAILURE));
	ctx.exec_name = av[0];
	if (init_sort_ptr(&ctx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((ctx.timestamp = time(&clock)) < 0)
		return (EXIT_FAILURE);
	run(&ctx, ac - 1, av + 1);
	return (EXIT_SUCCESS);
}
