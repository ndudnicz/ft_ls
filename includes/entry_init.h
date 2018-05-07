/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:00 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:03 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_INIT_H
# define ENTRY_INIT_H

t_entry		*init_entry(
	t_entry **new,
	struct stat s[2]
);

#endif
