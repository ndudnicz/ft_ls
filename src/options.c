/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:40:34 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:40:36 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "error.h"
#include "libftasm.h"
#include "options.h"

/*
** Moves NULLs argv to the end of the array. Options are set in config
** and doesn't exist anymore in argv.
*/

static void	del_null_params(
	int *ac,
	char **av,
	int offset
)
{
	int		i;
	int		n;
	char	*tmp;

	n = 1;
	while (n < *ac)
	{
		i = 1;
		while (i < *ac - 1)
		{
			if (av[i] == NULL)
			{
				tmp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = tmp;
			}
			i++;
		}
		n++;
	}
	*ac -= offset;
}

static int	switch_set_options(
	char const *exec_name,
	char const *arg,
	t_context *ctx
)
{
	if (!arg)
		return (0);
	else
		arg++;
	while (arg && *arg)
	{
		if (*arg && ft_strchr(PARAMS_STR, (int)(*arg)))
		{
			if (*arg == OPT_LONG_FORMAT_CHAR)
				ctx->options |= OPT_LONG_FORMAT;
			else if (*arg == OPT_RECURSIVE_CHAR)
				ctx->options |= OPT_RECURSIVE;
			else if (*arg == OPT_DOT_FILES_CHAR)
				ctx->options |= OPT_DOT_FILES;
			else if (*arg == OPT_REVERSE_CHAR)
				ctx->options |= OPT_REVERSE;
			else
				ctx->options |= OPT_SORT_TIME;
		}
		else
			return (ft_error(exec_name, "", UNKNOW_ARG, -1));
		arg++;
	}
	return (0);
}

/*
** Parse argv and set argv[i] at NULL if an options was found.
*/

int			get_options(
	t_context *ctx,
	int *ac,
	char **av
)
{
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (i < *ac && av[i][0] == '-' && ft_strlen(av[i]) > 1)
	{
		if (switch_set_options(av[0], av[i], ctx) < 0)
			return (1);
		n++;
		av[i++] = NULL;
	}
	del_null_params(ac, av, n);
	return (0);
}
