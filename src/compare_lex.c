#include "mystdint.h"
#include "entry.h"
#include "libftasm.h"

/*
** Slow compare functions, need to be improved :)
*/
t_s32	compare_lex_standard(t_entry *a, t_entry *b)
{
	return (ft_strcmp(a->name, b->name));
}

t_s32	compare_lex_reverse(t_entry *a, t_entry *b)
{
	return (ft_strcmp(b->name, a->name));
}
