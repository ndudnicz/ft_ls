#ifndef ENTRY_PUSH_SORT_H
# define ENTRY_PUSH_SORT_H

t_entry		*push_sort_entry(
	t_entry **begin,
	t_entry **new,
	t_s32	(*compare)(t_entry*, t_entry*)
);

#endif
