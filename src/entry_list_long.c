/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_list_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:40 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:39:41 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "entry.h"
#include "error.h"
#include "mystdint.h"
#include "entry_init_long.h"
#include "misc.h"

/*
** Create a new entry, init it and return it, -l -l -l -l
*/

t_entry	*create_long_entry(
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
)
{
	t_entry		*new;
	t_u64 const	size = sizeof(t_entry_long);

	new = NULL;
	if (!fullname || !dir || !(new = (t_entry*)my_calloc(sizeof(t_entry))) ||
		!set_names(new, dir->d_name, fullname) ||
		!(new->entry_long = (t_entry_long*)my_calloc(size)) ||
		!init_long_entry(new, s))
		return (pft_error("Error", "create_entry()", MALLOC_FAILED, NULL));
	else
		return (new);
}
