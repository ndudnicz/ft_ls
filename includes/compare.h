/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:37:40 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:37:42 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_H
# define COMPARE_H

t_s32	compare_lex_standard(
	t_entry *a,
	t_entry *b
);
t_s32	compare_lex_reverse(
	t_entry *a,
	t_entry *b
);

t_s32	compare_time_modified(
	t_entry *a,
	t_entry *b
);
t_s32	compare_time_modified_reverse(
	t_entry *a,
	t_entry *b
);

#endif
