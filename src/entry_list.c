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
	t_context *ctx,
	struct stat s[2],
	char const *const name,
	char const *const fullname
)
{
	t_entry		*new;

	new = NULL;
	if (!fullname || !name || !(new = (t_entry*)my_calloc(sizeof(t_entry))) ||
		!init_entry(&new, s) ||
		!set_names(&new, name, fullname))
		return (pft_free_perror(ctx, &new, name, NULL));
	else
		return (new);
}
