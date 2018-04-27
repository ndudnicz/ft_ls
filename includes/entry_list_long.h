#ifndef ENTRY_LIST_LONG_H
# define ENTRY_LIST_LONG_H

t_entry		*create_long_entry(
	t_entry **begin,
	struct stat s[2],
	struct dirent *dir,
	char const *fullname
);

#endif
