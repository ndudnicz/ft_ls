/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:32 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:33 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "entry.h"
#include "error.h"
#include "mystdint.h"
#include "entry_init.h"
#include "misc.h"

/*
** Create a new entry, init it and return it
*/

t_entry				*create_entry(
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
)
{
	t_entry		*new;

	new = NULL;
	if (!fullname || !dir || !(new = (t_entry*)my_calloc(sizeof(t_entry))) ||
		!init_entry(new, s) ||
		!set_names(new, dir->d_name, fullname))
		return (pft_error("Error", "create_entry()", MALLOC_FAILED, NULL));
	else
		return (new);
}
