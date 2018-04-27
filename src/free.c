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

void	free_entry_long(t_entry **entry)
{
	free((*entry)->entry_long->username);
	(*entry)->entry_long->username = NULL;
	free((*entry)->entry_long->grp_name);
	(*entry)->entry_long->grp_name = NULL;
	free((*entry)->entry_long);
	(*entry)->entry_long = NULL;
	// if ((*entry)->entry_long->sym_name)
		// free((*entry)->entry_long->sym_name);
	free_entry(entry);
}
