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
	struct stat		stat[2];
	t_s64			t;

	lstat((char*)a, &stat[0]);
	lstat((char*)b, &stat[1]);
	if ((S_ISDIR(stat[0].st_mode) && S_ISDIR(stat[1].st_mode)) ||
	(!S_ISDIR(stat[0].st_mode) && !S_ISDIR(stat[1].st_mode)))
	{
		t = stat[1].st_mtimespec.tv_sec - stat[0].st_mtimespec.tv_sec;
		if (t > 0)
			return (1);
		else if (t < 0)
			return (-1);
		else
			return (args_compare_lex_standard(a, b));
	}
	else if (S_ISDIR(stat[0].st_mode))
		return (1);
	else
		return (-1);
}

t_s32	args_compare_time_modified_reverse(
	void *a,
	void *b
)
{
	struct stat		stat[2];
	t_s64			t;

	lstat((char*)a, &stat[0]);
	lstat((char*)b, &stat[1]);
	if ((S_ISDIR(stat[0].st_mode) && S_ISDIR(stat[1].st_mode)) ||
	(!S_ISDIR(stat[0].st_mode) && !S_ISDIR(stat[1].st_mode)))
	{
		t = stat[0].st_mtimespec.tv_sec - stat[1].st_mtimespec.tv_sec;
		if (t > 0)
			return (1);
		else if (t < 0)
			return (-1);
		else
			return (args_compare_lex_reverse(a, b));
	}
	else if (S_ISDIR(stat[0].st_mode))
		return (1);
	else
		return (-1);
}
