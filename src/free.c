#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"

void	free_entry(t_entry **entry)
{
	free((*entry)->fullname);
	(*entry)->fullname = NULL;
	free((*entry)->name);
	(*entry)->name = NULL;
	free((*entry));
	*entry = NULL;
}
