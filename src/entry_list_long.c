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
	t_context *ctx,
	struct stat s[2],
	char const *const name,
	char const *const fullname
)
{
	t_entry		*new;
	t_u64 const	size = sizeof(t_entry_long);

	new = NULL;
	if (!fullname || !name || !(new = (t_entry*)my_calloc(sizeof(t_entry))) ||
	!(new->entry_long = (t_entry_long*)my_calloc(size)))
		return (NULL);
	else if (!set_names(&new, name, fullname))
		return (pft_free_perror(ctx, &new, name, NULL));
	else if (!init_long_entry(ctx, &new, s))
		return (NULL);
	else
		return (new);
}
