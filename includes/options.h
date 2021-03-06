/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:56 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:57 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include "mystdint.h"
# include "entry.h"

# define TIME					15724800

# define OPT_REVERSE			0x01
# define OPT_SORT_TIME			0x02
# define OPT_LONG_FORMAT		0x08
# define OPT_RECURSIVE			0x10
# define OPT_DOT_FILES			0x20

# define SORT_MASK				0x07
# define TIME_SORT_MASK			0x06

# define OPT_LONG_FORMAT_CHAR		'l'
# define OPT_RECURSIVE_CHAR			'R'
# define OPT_DOT_FILES_CHAR			'a'
# define OPT_REVERSE_CHAR			'r'
# define OPT_SORT_TIME_CHAR			't'

# define PARAMS_STR				"lRart"

typedef t_s32			(*t_sort_ptr)(t_entry*, t_entry*);

typedef struct	s_context
{
	t_sort_ptr		sort_ptr;
	t_s64			timestamp;
	char			*exec_name;
	t_s32			ret;
	t_u8			options;
}				t_context;

int				get_options(
	t_context *ctx,
	int *ac,
	char **av
);

void			del_null_params(
	int *ac,
	char **av,
	int offset
);

#endif
