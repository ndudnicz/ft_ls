#ifndef DISPLAY_H
# define DISPLAY_H

int		display_root_entries(
	t_context *ctx,
	t_entry **begin
	// char const * const rootname
	// char const is_in_node
);

int		display_entries(
	t_context *ctx,
	t_entry **begin,
	char const is_in_node
);

int		display_entries_debug(
	t_context *ctx,
	t_entry **begin,
	char const is_in_node
);

#endif
