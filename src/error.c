#include "libftasm.h"
#include "libft.h"

int		ft_error(char const *s1, char const *s2, char const *s3, int const ret)
{
	ft_putstr(s1);
	ft_putstr(": ");
	ft_putstr(s2);
	ft_putstr(": ");
	ft_putendl(s3);
	return (ret);
}
