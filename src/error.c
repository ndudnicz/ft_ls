#include <stdio.h>
#include <stdlib.h>

#include "libftasm.h"
#include "libft.h"

int		ft_error(
	char const * const s1,
	char const * const s2,
	char const * const s3,
	int const ret
)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(s3, 2);
	return (ret);
}

int		ft_perror(
	char const * const s1,
	char const * const s2,
	int const ret
)
{
	char const	*err = ft_strjoin_free(ft_strjoin(s1, ": "), s2, 1, 0);

	if (err)
	{
		perror(err);
		free((void*)err);
	}
	else
		perror(NULL);
	return (ret);
}

void	*pft_error(
	char const * const s1,
	char const * const s2,
	char const * const s3,
	void *ret
)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(s3, 2);
	return (ret);
}

void	*pft_perror(
	char const * const s1,
	char const * const s2,
	void *ret
)
{
	char const	*err = ft_strjoin_free(ft_strjoin(s1, ": "), s2, 1, 0);

	if (err)
	{
		perror(err);
		free((void*)err);
	}
	else
		perror(NULL);
	return (ret);
}
