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
