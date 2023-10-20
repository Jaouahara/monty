#include "monty.h"

/**
  *fun_sub- sub the top
  *@hd: stack head
  *@ct: line number
  *Return: void
 */
void fun_sub(stack_t **hd, unsigned int ct)
{
	stack_t *bus;
	int c, nod;

	bus = *hd;
	for (nod = 0; bus != NULL; nod++)
		bus = bus->next;
	if (nod < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ct);
		fclose(aug.file);
		free(aug.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	bus = *hd;
	c = bus->next->n - bus->n;
	bus->next->n = c;
	*hd = bus->next;
	free(bus);
}
