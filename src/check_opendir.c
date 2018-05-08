/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opendir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:23:18 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/08 15:23:19 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "options.h"
#include "error.h"

int		check_opendir(
	t_context *ctx,
	int *ac,
	char **av
)
{
	DIR		*dirp;
	int		n;
	int		i;

	dirp = NULL;
	n = 0;
	i = 0;
	while (i < *ac)
	{
		if ((dirp = opendir(av[i])) == NULL && errno == ENOENT)
		{
			n++;
			(void)ft_free_perror(ctx, NULL, av[i], 0);
			av[i] = NULL;
		}
		else if (dirp)
			closedir(dirp);
		i++;
	}
	del_null_params(ac, av, n);
	return (0);
}
