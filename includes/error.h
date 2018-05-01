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
	char const *const s1,
	char const *const s2,
	int const ret
);
void	*pft_error(
	char const *const s1,
	char const *const s2,
	char const *const s3,
	void *ret
);
void	*pft_perror(
	char const *const s1,
	char const *const s2,
	void *ret
);

#endif
