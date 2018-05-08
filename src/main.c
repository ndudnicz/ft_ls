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
#include "error.h"
#include "run.h"
#include "libft.h"

static t_s32	usage(t_s32 const ret)
{
	ft_putstr_fd("usage: ./ft_ls [-Rrlta] [file ...]\n", 2);
	return (ret);
}

static t_s32	init_sort_ptr(t_context *ctx)
{
	if (ctx->options & OPT_SORT_TIME)
	{
		if (ctx->options & OPT_REVERSE)
			ctx->sort_ptr = &compare_time_modified_reverse;
		else
			ctx->sort_ptr = &compare_time_modified;
	}
	else
	{
		if (ctx->options & OPT_REVERSE)
			ctx->sort_ptr = &compare_lex_reverse;
		else
			ctx->sort_ptr = &compare_lex_standard;
	}
	return (EXIT_SUCCESS);
}

int				main(
	int ac,
	char **av
)
{
	t_context	ctx;
	time_t		clock;

	ft_memset((void*)&ctx, 0, sizeof(t_context));
	if (!(ctx.exec_name = ft_strdup(av[0])))
		return (EXIT_FAILURE);
	av[0] = NULL;
	if (get_options(&ctx, &ac, av))
		return (usage(EXIT_FAILURE));
	if (init_sort_ptr(&ctx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((ctx.timestamp = time(&clock)) < 0)
		return (EXIT_FAILURE);
	run(&ctx, ac - 1, av);
	free(ctx.exec_name);
	return (ctx.ret);
}
