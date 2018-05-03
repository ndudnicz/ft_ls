/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sizes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:49:25 by ndudnicz          #+#    #+#             */
/*   Updated: 2018/05/03 14:49:26 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "options.h"
#include "entry.h"
#include "libftasm.h"
#include "libft.h"

static int		set_major_minor_sizes(
	t_entry *new
)
{
	if (new->mode & MODE_SPEC_MASK)
	{
		if (new->data->entry_long->sizes.biggest_major <
		major(new->stat.st_rdev))
		{
			new->data->entry_long->sizes.biggest_major =
			major(new->stat.st_rdev);
			new->data->entry_long->sizes.biggest_major_len =
			ft_numberlen(new->data->entry_long->sizes.biggest_major, 10);
		}
		if (new->data->entry_long->sizes.biggest_major <
		minor(new->stat.st_rdev))
		{
			new->data->entry_long->sizes.biggest_major =
			minor(new->stat.st_rdev);
			new->data->entry_long->sizes.biggest_major_len =
			ft_numberlen(new->data->entry_long->sizes.biggest_major, 10);
		}
		new->data->entry_long->sizes.biggest_size_len = 2 +
		new->data->entry_long->sizes.biggest_major_len +
		new->data->entry_long->sizes.biggest_major_len;
	}
	return (0);
}

static int		set_sizes_norme(
	t_entry **bgn,
	t_entry *new
)
{
	(*bgn)->data->entry_long->sizes.biggest_size = new->lstat.st_size;
	(*bgn)->data->entry_long->sizes.biggest_size_len =
	ft_numberlen(new->lstat.st_size, 10);
	return (0);
}

void			set_sizes(
	t_context *ctx,
	t_entry **bgn,
	t_entry *new
)
{
	t_u64 const		usr_len = ft_strlen(new->entry_long->username);
	t_u64 const		grp_len = ft_strlen(new->entry_long->grp_name);

	new->data = (*bgn)->data;
	(void)set_major_minor_sizes(new);
	if ((ctx->options & OPT_DOT_FILES) || new->name[0] != '.')
	{
		if (new->lstat.st_nlink > (*bgn)->data->entry_long->sizes.biggest_nlink)
		{
			(*bgn)->data->entry_long->sizes.biggest_nlink = new->lstat.st_nlink;
			(*bgn)->data->entry_long->sizes.biggest_nlink_len =
			ft_numberlen(new->lstat.st_nlink, 10);
		}
		if (new->lstat.st_size > (*bgn)->data->entry_long->sizes.biggest_size &&
		ft_numberlen(new->lstat.st_size, 10) >
		(t_s32)(*bgn)->data->entry_long->sizes.biggest_size_len)
		{
			(void)set_sizes_norme(bgn, new);
		}
		if (usr_len > (*bgn)->data->entry_long->sizes.biggest_usr_len)
			(*bgn)->data->entry_long->sizes.biggest_usr_len = usr_len;
		if (grp_len > (*bgn)->data->entry_long->sizes.biggest_grp_len)
			(*bgn)->data->entry_long->sizes.biggest_grp_len = grp_len;
	}
	(*bgn)->data->entry_long->total += new->lstat.st_blocks;
}
