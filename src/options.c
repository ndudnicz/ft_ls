#include <stdlib.h>

#include "options.h"
#include "error.h"
#include "libftasm.h"

/*
** Moves NULLs argv to the end of the array. Options are set in config
** and doesn't exist anymore in argv.
*/

static void	del_null_params(
	int *ac,
	char **av,
	int offset
)
{
	int		i;
	int		n;
	char	*tmp;

	n = 1;
	while (n < *ac)
	{
		i = 1;
		while (i < *ac - 1)
		{
			if (av[i] == NULL)
			{
				tmp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = tmp;
			}
			i++;
		}
		n++;
	}
	*ac -= offset;
}

static int		switch_set_options(
	char const *exec_name,
	char const *arg,
	t_context *ctx
)
{
	if (!arg)
		return (0);
	else
		arg++;
	while (arg && *arg)
	{
		if (*arg && ft_strchr(PARAMS_STR, (int)(*arg)))
		{
			if (*arg == OPT_LONG_FORMAT_CHAR)
				ctx->options |= OPT_LONG_FORMAT;
			else if (*arg == OPT_RECURSIVE_CHAR)
				ctx->options |= OPT_RECURSIVE;
			else if (*arg == OPT_DOT_FILES_CHAR)
				ctx->options |= OPT_DOT_FILES;
			else if (*arg == OPT_DOT_REVERSE_CHAR)
				ctx->options |= OPT_DOT_REVERSE;
			else
				ctx->options |= OPT_SORT_TIME;
		}
		else
			return (ft_error(exec_name, "", UNKNOW_ARG, -1));
		arg++;
	}
	return (0);
}

/*
** Parse argv and set argv[i] at NULL if an options was found.
*/

int	get_options(
	t_context *ctx,
	int *ac,
	char **av
)
{
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (i < *ac && av[i][0] == '-' && ft_strlen(av[i]) > 1)
	{
		if (switch_set_options(av[0], av[i], ctx) < 0)
			return (1);
		n++;
		av[i++] = NULL;
	}
	del_null_params(ac, av, n);
	return (0);
}

/*
** return 0 if ok, 1 and display an error msg if not ok
*/

int	valid_options(
	// char const *exec_name,
	// t_context *ctx
)
{
	return (0);
	// if (options->st_key.key_size == KEY_LENGTH && (options->options & OPT_FILE)) {
	// 	return 0;
	// } else if (
	// 	options->st_key.key_size != KEY_LENGTH &&
	// 	((options->options & (OPT_GEN_KEY | OPT_FILE)) == (OPT_GEN_KEY | OPT_FILE))
	// ) {
	// 	return 0;
	// } else {
	// 	if (!(options->options & OPT_FILE)) {
	// 		return ft_error(exec_name, "valid_options()", MISSING_INPUT_FILE, 1);
	// 	} else if (options->st_key.key_size != KEY_LENGTH && !(options->options & OPT_GEN_KEY)) {
	// 		return ft_error(exec_name, "valid_options()", INVALID_KEY_LENGTH, 1);
	// 	} else {
	// 		return ft_error(exec_name, "valid_options()", UNKNOW_ERROR, 1);
	// 	}
	// }
}
