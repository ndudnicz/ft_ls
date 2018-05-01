/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_lex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:05 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:06 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystdint.h"
#include "entry.h"
#include "libftasm.h"

/*
** Slow compare functions, need to be improved :)
*/

t_s32	compare_lex_standard(t_entry *a, t_entry *b)
{
	return (ft_strcmp(a->name, b->name));
}

t_s32	compare_lex_reverse(t_entry *a, t_entry *b)
{
	return (ft_strcmp(b->name, a->name));
}
