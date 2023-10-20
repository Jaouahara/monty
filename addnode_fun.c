#include "monty.h"
/**
 * addnode - function add
 * @hd: head
 * @n: new_value
 * Return: void
*/
void addnode(stack_t **hd, int n)
{

	stack_t *new_node, *bus;

	bus = *hd;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (bus)
		bus->prev = new_node;
	new_node->n = n;
	new_node->next = *hd;
	new_node->prev = NULL;
	*hd = new_node;
}
