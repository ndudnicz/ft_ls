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
