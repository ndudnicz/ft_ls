/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:21 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:23 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entry.h"
#include "libftasm.h"

/*
** Init the new entry
*/

t_entry		*init_entry(
	t_entry *new,
	struct stat s[2]
)
{
	new->mode |= S_ISDIR(s[1].st_mode) ? MODE_IS_NODE : 0;
	new->mode |= S_ISLNK(s[1].st_mode) ? MODE_IS_SYM : 0;
	new->mode |= S_ISCHR(s[1].st_mode) ? MODE_IS_CHR : 0;
	new->mode |= S_ISBLK(s[1].st_mode) ? MODE_IS_BLK : 0;
	ft_memcpy((void*)&new->stat, (void*)&s[0], sizeof(struct stat));
	ft_memcpy((void*)&new->lstat, (void*)&s[1], sizeof(struct stat));
	return (new);
}
