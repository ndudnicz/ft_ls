/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_compare_lex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:05 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:06 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystdint.h"
#include "libftasm.h"
#include <sys/stat.h>

/*
** Slow compare functions, need to be improved :)
*/

t_s32	args_compare_lex_standard(
	void *a,
	void *b
)
{
	struct stat		lstat_a;
	struct stat		lstat_b;

	lstat((char*)a, &lstat_a);
	lstat((char*)b, &lstat_b);
	if ((S_ISDIR(lstat_a.st_mode) && S_ISDIR(lstat_b.st_mode)) ||
	(!S_ISDIR(lstat_a.st_mode) && !S_ISDIR(lstat_b.st_mode)))
		return (ft_strcmp((char*)a, (char*)b));
	else if (S_ISDIR(lstat_a.st_mode))
		return (1);
	else
		return (-1);
}

t_s32	args_compare_lex_reverse(
	void *a,
	void *b
)
{
	struct stat		lstat_a;
	struct stat		lstat_b;

	lstat((char*)a, &lstat_a);
	lstat((char*)b, &lstat_b);
	if ((S_ISDIR(lstat_a.st_mode) && S_ISDIR(lstat_b.st_mode)) ||
	(!S_ISDIR(lstat_a.st_mode) && !S_ISDIR(lstat_b.st_mode)))
		return (ft_strcmp((char*)b, (char*)a));
	else if (S_ISDIR(lstat_a.st_mode))
		return (1);
	else
		return (-1);
}
