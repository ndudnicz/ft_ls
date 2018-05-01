/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:43:26 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 16:43:27 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystdint.h"
#include "libft.h"
#include "libftasm.h"
#include "args_compare.h"
#include "options.h"
#include "entry_parse.h"
#include "entry_parse_long.h"

static void			sort_args(
	t_context *ctx,
	int ac,
	char **av
)
{
	if ((ctx->options & SORT_MASK) == 0)
	{
		ft_qsort((void**)av, 0, ac - 1, &args_compare_lex_standard);
	}
	else if ((ctx->options & SORT_MASK) == OPT_REVERSE)
	{
		ft_qsort((void**)av, 0, ac - 1, &args_compare_lex_reverse);
	}
	else if ((ctx->options & SORT_MASK) == OPT_SORT_TIME)
	{
		ft_qsort((void**)av, 0, ac - 1, &args_compare_time_modified);
	}
	else if ((ctx->options & SORT_MASK) == OPT_REVERSE + OPT_SORT_TIME)
	{
		ft_qsort((void**)av, 0, ac - 1, &args_compare_time_modified_reverse);
	}
}

static t_entry		*switch_make_entries(
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

void				run(
	t_context *ctx,
	int ac,
	char **av
)
{
	t_s32	i;

	i = 0;
	if (ac > 1)
	{
		sort_args(ctx, ac, av);
		while (i < ac)
		{
			if (i > 0)
				ft_putchar('\n');
			ft_putstr(av[i]);
			ft_puts(":");
			switch_make_entries(ctx, av[i]);
			i++;
		}
	}
	else
	{
		switch_make_entries(ctx, ".");
	}
}
