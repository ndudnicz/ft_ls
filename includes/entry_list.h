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
	struct dirent *dir,
	char const *fullname
);

t_entry		*create_long_entry(
	t_entry **begin,
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
);

#endif
