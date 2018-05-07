/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:41 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:42 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "options.h"

# define MALLOC_FAILED "malloc() failed."
# define UNKNOW_ARG "Unknown argument."
# define UNKNOWN_ERROR "Unknow error."

int		ft_error(
	char const *const s1,
	char const *const s2,
	char const *const s3,
	int const ret
);

void	*pft_free_perror(
	t_context *ctx,
	t_entry **entry,
	char const *const path,
	void *ret
);

t_s32	ft_free_perror(
	t_context *ctx,
	t_entry **entry,
	char const *const path,
	t_s32 ret
);

#endif
