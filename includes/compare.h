#ifndef COMPARE_H
# define COMPARE_H

/* compare_lex.c */
t_s32	compare_lex_standard(
	t_entry *a,
	t_entry *b
);
t_s32	compare_lex_reverse(
	t_entry *a,
	t_entry *b
);

/* compare_time.c */
t_s32	compare_time_modified(
	t_entry *a,
	t_entry *b
);
t_s32	compare_time_modified_reverse(
	t_entry *a,
	t_entry *b
);

#endif
