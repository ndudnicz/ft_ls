/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:50 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:51 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# define CUR_DIR_STR		"."
# define PARENT_DIR_STR		".."

# include "options.h"
# include "mystdint.h"

typedef struct	s_var_box
{
	t_context			*ctx;
	char				*exec_name;
	t_entry				**begin;
	struct dirent		*dp;
	char				*path;

}				t_var_box;

int				is_dot_double_dot(char const *const filename);

void			*my_calloc(t_u64 const size);

t_entry			*set_names(
	t_entry *new,
	char const *const name,
	char const *const fullname
);

void			ft_putuint64(t_u64 n);

void			print_3_strings(
	char const *const s1,
	char const *const s2,
	char const *const s3
);

#endif
