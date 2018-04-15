#include <stdlib.h>

#include "entry.h"
#include "libftasm.h"

static void	free_entry(t_entry *entry)
{
	free((void*)entry->name);
	free((void*)entry->fullname);
	ft_memset(entry, 0, sizeof(t_entry));
	free((void*)entry);
}

void	free_entries(
	t_context *ctx,
	t_entry **begin
)
{
	t_entry	*tmp;
	t_entry	*next;

	tmp = *begin;
	while (tmp)
	{
		if (tmp->node)
			free_entries(ctx, &tmp->node);
		next = tmp->next;
		free_entry(tmp);
		tmp = next;
	}
}
