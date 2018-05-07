/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_compare_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:09 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:10 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystdint.h"
#include "args_compare.h"
#include <sys/stat.h>

t_s32	args_compare_time_modified(
	void *a,
	void *b
)
{
	struct stat		lstat_a;
	struct stat		lstat_b;
	t_s64			t;

	lstat((char*)a, &lstat_a);
	lstat((char*)b, &lstat_b);
	if ((S_ISDIR(lstat_a.st_mode) && S_ISDIR(lstat_b.st_mode)) ||
	(!S_ISDIR(lstat_a.st_mode) && !S_ISDIR(lstat_b.st_mode)))
	{
		t = lstat_b.st_mtimespec.tv_sec - lstat_a.st_mtimespec.tv_sec;
		if (t > 0)
			return (1);
		else if (t < 0)
			return (-1);
		else
			return (args_compare_lex_standard(a, b));
	}
	else if (S_ISDIR(lstat_a.st_mode))
		return (1);
	else
		return (-1);
}

t_s32	args_compare_time_modified_reverse(
	void *a,
	void *b
)
{
	struct stat		lstat_a;
	struct stat		lstat_b;
	t_s64			t;

	lstat((char*)a, &lstat_a);
	lstat((char*)b, &lstat_b);
	if ((S_ISDIR(lstat_a.st_mode) && S_ISDIR(lstat_b.st_mode)) ||
	(!S_ISDIR(lstat_a.st_mode) && !S_ISDIR(lstat_b.st_mode)))
	{
		t = lstat_a.st_mtimespec.tv_sec - lstat_b.st_mtimespec.tv_sec;
		if (t > 0)
			return (1);
		else if (t < 0)
			return (-1);
		else
			return (args_compare_lex_reverse(a, b));
	}
	else if (S_ISDIR(lstat_a.st_mode))
		return (1);
	else
		return (-1);
}
