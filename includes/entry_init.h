#ifndef ENTRY_INIT_H
# define ENTRY_INIT_H

t_entry		*init_entry(
	t_entry **begin,
	t_entry *new,
	struct stat s[2]
);

t_entry		*init_long_entry(
	t_entry **begin,
	t_entry *new,
	struct stat s[2]
);

#endif
