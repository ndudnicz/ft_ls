/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_init_long.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:07 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:09 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_INIT_LONG_H
# define ENTRY_INIT_LONG_H

# include "options.h"

t_entry		*init_long_entry(
	t_entry *new,
	struct stat s[2]
);

t_s32		set_date(
	t_context *ctx,
	t_entry *new,
	struct stat *s
);

#endif
