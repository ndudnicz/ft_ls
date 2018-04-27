#ifndef ENTRY_LIST_H
# define ENTRY_LIST_H

t_entry		*create_entry(
	t_u64 const length,
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
);

t_entry		*create_long_entry(
	t_u64 const length,
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
);

#endif
