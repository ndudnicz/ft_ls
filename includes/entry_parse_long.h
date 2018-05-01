/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_parse_long.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:27 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:28 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_PARSE_LONG_H
# define ENTRY_PARSE_LONG_H

t_entry		*make_entries_long(
	t_context *ctx,
	t_entry *begin,
	char *path
);

t_entry		*make_entries_recursive_long(
	t_context *ctx,
	t_entry *begin,
	char *path
);

#endif
