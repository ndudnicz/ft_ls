/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_list_long.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:17 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:18 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_LIST_LONG_H
# define ENTRY_LIST_LONG_H

t_entry		*create_long_entry(
	t_context *ctx,
	struct stat s[2],
	char const *const name,
	char const *const fullname
);

#endif
