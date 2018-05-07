/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_compare.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:37:40 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:37:42 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_COMPARE_H
# define ARGS_COMPARE_H

t_s32	args_compare_lex_standard(
	void *a,
	void *b
);
t_s32	args_compare_lex_reverse(
	void *a,
	void *b
);

t_s32	args_compare_time_modified(
	void *a,
	void *b
);
t_s32	args_compare_time_modified_reverse(
	void *a,
	void *b
);

t_s32	args_compare_access_time_modified(
	void *a,
	void *b
);
t_s32	args_compare_access_time_modified_reverse(
	void *a,
	void *b
);

#endif
