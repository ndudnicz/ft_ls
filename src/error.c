/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:40:05 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:40:07 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libftasm.h"
#include "libft.h"
#include "mystdint.h"
#include "options.h"

t_s32	ft_error(
	char const *const s1,
	char const *const s2,
	char const *const s3,
	t_s32 const ret
)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(s3, 2);
	return (ret);
}

t_s32	ft_perror(
	t_context *ctx,
	char const *const s1,
	char const *const s2,
	t_s32 const ret
)
{
	char const	*err = ft_strjoin_free(ft_strjoin(s1, ": "), s2, 1, 0);

	if (err)
	{
		perror(err);
		free((void*)err);
	}
	else
		perror(NULL);
	ctx->ret = 1;
	return (ret);
}

void	*pft_error(
	char const *const s1,
	char const *const s2,
	char const *const s3,
	void *ret
)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(s3, 2);
	return (ret);
}

void	*pft_perror(
	t_context *ctx,
	char const *const s1,
	char const *const s2,
	void *ret
)
{
	char const	*err = ft_strjoin_free(ft_strjoin(s1, ": "), s2, 1, 0);

	if (err)
	{
		perror(err);
		free((void*)err);
	}
	else
		perror(NULL);
	ctx->ret = 1;
	return (ret);
}
