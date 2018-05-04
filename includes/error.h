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
# define INVALID_ARG "Invalid argument."
# define OPEN_FAILED "open() failed."
# define READDIR_FAILED "readdir() failed."
# define UNKNOWN_ERROR "Unknow error."
# define TIME_FAILED "time() failed."

int		ft_error(
	char const *const s1,
	char const *const s2,
	char const *const s3,
	int const ret
);
int		ft_perror(
	t_context *ctx,
	char const *const s1,
	char const *const s2,
	int const ret
);

// void	*pft_free_error(
// 	t_context *ctx,
// 	t_entry *entry,
// 	void *ret
// );

void	*pft_free_perror(
	t_context *ctx,
	t_entry *entry,
	void *ret
);

#endif
