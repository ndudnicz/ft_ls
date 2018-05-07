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

#include "options.h"
#include "libftasm.h"
#include "libft.h"
#include "mystdint.h"
#include "free.h"

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

void	*pft_free_perror(
	t_context *ctx,
	t_entry **entry,
	char const *const path,
	void *ret
)
{
	char	*err;

	if (entry && *entry)
		err = ft_strjoin_free(ft_strjoin(ctx->exec_name, ": "),
		(*entry)->name, 1, 0);
	else if (path)
		err = ft_strjoin_free(ft_strjoin(ctx->exec_name, ": "), path, 1, 0);
	else
		err = ft_strdup(ctx->exec_name);
	if (err)
	{
		perror(err);
		free((void*)err);
	}
	else
		perror(NULL);
	ctx->ret = 1;
	if (entry && *entry)
	{
		if ((*entry)->entry_long)
			free_entry_long(entry);
		else
			free_entry(entry);
	}
	return (ret);
}

t_s32	ft_free_perror(
	t_context *ctx,
	t_entry **entry,
	char const *const path,
	t_s32 ret
)
{
	char	*err;

	if (entry && *entry)
		err = ft_strjoin_free(ft_strjoin(ctx->exec_name, ": "),
		(*entry)->name, 1, 0);
	else if (path)
		err = ft_strjoin_free(ft_strjoin(ctx->exec_name, ": "), path, 1, 0);
	else
		err = ft_strdup(ctx->exec_name);
	if (err)
	{
		perror(err);
		free((void*)err);
	}
	else
		perror(NULL);
	ctx->ret = 1;
	if (entry && *entry)
	{
		if ((*entry)->entry_long)
			free_entry_long(entry);
		else
			free_entry(entry);
	}
	return (ret);
}
