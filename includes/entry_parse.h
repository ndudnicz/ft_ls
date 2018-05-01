/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:38:22 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/01 12:38:23 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_PARSE_H
# define ENTRY_PARSE_H

t_entry		*make_entries(
	t_context *ctx,
	t_entry *begin,
	char *path
);

t_entry		*make_entries_recursive(
	t_context *ctx,
	t_entry *begin,
	char *path
);

#endif
