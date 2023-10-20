#include "monty.h"
/**
 * fun_queue - function
 * @hd: stack head
 * @ct: number of line
 * Return: void
*/
void fun_queue(stack_t **hd, unsigned int ct)
{
	(void)hd;
	(void)ct;
	aug.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @hd: head
 * Return: no return
*/
void addqueue(stack_t **hd, int n)
{
	stack_t *new_node, *bus;

	bus = *hd;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (bus)
	{
		while (bus->next)
			bus = bus->next;
	}
	if (!bus)
	{
		*hd = new_node;
		new_node->prev = NULL;
	}
	else
	{
		bus->next = new_node;
		new_node->prev = bus;
	}
}
