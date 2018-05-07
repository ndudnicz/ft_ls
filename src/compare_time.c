/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:09 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:10 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entry.h"
#include "mystdint.h"
#include "compare.h"

t_s32	compare_time_modified(
	t_entry *a,
	t_entry *b
)
{
	t_s64 const	t = b->lstat.st_mtimespec.tv_sec - a->lstat.st_mtimespec.tv_sec;

	if (t > 0)
		return (1);
	else if (t < 0)
		return (-1);
	else
		return (compare_lex_standard(a, b));
}

t_s32	compare_time_modified_reverse(
	t_entry *a,
	t_entry *b
)
{
	t_s64 const	t = a->lstat.st_mtimespec.tv_sec - b->lstat.st_mtimespec.tv_sec;

	if (t > 0)
		return (1);
	else if (t < 0)
		return (-1);
	else
		return (compare_lex_reverse(a, b));
}
