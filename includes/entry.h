/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:37:54 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:37:55 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_H
# define ENTRY_H

# include <sys/stat.h>
#include <dirent.h>

# include "mystdint.h"

# define	MODE_IS_NODE	0x01
# define	MODE_IS_SYM		0x02

typedef struct		s_sizes
{
	t_s64	biggest_size;
	t_u64	biggest_size_len;
	t_u64	biggest_nlink;
	t_u64	biggest_nlink_len;
	t_u64	biggest_usr_len;
	t_u64	biggest_grp_len;
}					t_sizes;

typedef struct		s_entry_long
{
	char	sym_name[__DARWIN_MAXNAMLEN];
	t_sizes	sizes;
	char	date[13];
	char	rights[11];
	t_u64	total;
	char	*username; // malloc
	char	*grp_name; // malloc
}					t_entry_long;

typedef struct		s_entry
{
	struct stat		stat;
	struct stat		lstat;
	struct s_entry	*next;
	struct s_entry	*prev;
	struct s_entry	*begin;
	struct s_entry	*last;
	struct s_entry	*node;
	t_entry_long	*entry_long; // malloc
	char			*name; // malloc
	char			*fullname; // malloc
	char			mode;
}					t_entry;

#endif
