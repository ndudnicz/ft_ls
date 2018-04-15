#include "entry.h"
#include "mystdint.h"
#include "compare.h"

t_s32	compare_time_modified(
	t_entry* a,
	t_entry *b
)
{
	t_s64 const	tmp = b->stat.st_mtimespec.tv_sec - a->stat.st_mtimespec.tv_sec;

	// printf("%s %ld %s %ld\n", a->name, a->stat.st_mtimespec.tv_sec, b->name, b->stat.st_mtimespec.tv_sec);
	if (tmp > 0)
		return (1);
	else if (tmp < 0)
		return (-1);
	else
		return (compare_lex_standard(a, b));
}

t_s32	compare_time_modified_reverse(
	t_entry* a,
	t_entry *b
)
{
	t_s64 const	tmp = a->stat.st_mtimespec.tv_sec - b->stat.st_mtimespec.tv_sec;

	// printf("%s %ld %s %ld\n", a->name, a->stat.st_mtimespec.tv_sec, b->name, b->stat.st_mtimespec.tv_sec);
	if (tmp > 0)
		return (1);
	else if (tmp < 0)
		return (-1);
	else
		return (compare_lex_reverse(a, b));
}
