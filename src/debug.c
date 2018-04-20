#include "entry.h"

void display_list(t_entry *begin){
	printf("------------------\n", begin->name);
	while (begin && begin->name){
		printf("%s\n", begin->name);
		begin = begin->next;
	}
	printf("------------------\n", begin->name);
}
