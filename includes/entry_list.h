/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:12 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:13 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_LIST_H
# define ENTRY_LIST_H

t_entry		*create_entry(
	struct stat s[2],
	char const *const name,
	char const *const fullname
);

#endif
