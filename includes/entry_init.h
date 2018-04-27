#ifndef ENTRY_INIT_H
# define ENTRY_INIT_H

t_entry		*init_entry(
	t_entry *new,
	t_u64 const length,
	struct stat s[2],
	t_u8 const name_len
);

t_entry		*init_long_entry(
	t_entry *new,
	t_u64 const length,
	struct stat s[2],
	t_u8 const name_len
);

#endif
