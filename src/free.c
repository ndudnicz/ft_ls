/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:40:12 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:40:13 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "entry.h"

void	free_entry(t_entry **entry)
{
	free((*entry)->fullname);
	(*entry)->fullname = NULL;
	free((*entry)->name);
	(*entry)->name = NULL;
	free((*entry));
	*entry = NULL;
}

void	free_entry_long(t_entry **entry)
{
	free((*entry)->entry_long->username);
	(*entry)->entry_long->username = NULL;
	free((*entry)->entry_long->grp_name);
	(*entry)->entry_long->grp_name = NULL;
	free((*entry)->entry_long);
	(*entry)->entry_long = NULL;
	free_entry(entry);
}
