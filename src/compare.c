#include "mystdint.h"
#include "entry.h"
#include "libftasm.h"

t_s32	compare_alpha(t_entry* a, t_entry *b)
{
	return (ft_strcmp(a->name, b->name));
}