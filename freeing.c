#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @hd: head
*/
void free_stack(stack_t *hd)
{
	stack_t *bus;

	bus = hd;
	while (hd)
	{
		bus = hd->next;
		free(hd);
		hd = bus;
	}
}
