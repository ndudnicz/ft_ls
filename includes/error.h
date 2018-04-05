#ifndef ERROR_H
# define ERROR_H

# define MALLOC_FAILED "malloc() failed."
# define UNKNOW_ARG "Unknown argument."
# define INVALID_ARG "Invalid argument."
# define OPEN_FAILED "open() failed."
# define UNKNOW_ERROR "Unknow error."

int	ft_error(char const *s1, char const *s2, char const *s3, int const ret);

#endif
