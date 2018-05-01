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

/*
** Slow compare functions, need to be improved :)
*/

t_s32	args_compare_lex_standard(
	void *a,
	void *b
)
{
	return (ft_strcmp((char*)a, (char*)b));
}

t_s32	args_compare_lex_reverse(
	void *a,
	void *b
)
{
	return (ft_strcmp((char*)b, (char*)a));
}
