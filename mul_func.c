#include "monty.h"

/**
 * fun_mul - mul the top two elements of the stack
 * @hd: stack head
 * @ct: line number
 * Return: void
*/
void fun_mul(stack_t **hd, unsigned int ct)
{
	stack_t *x;
	int l = 0, bus;

	x = *hd;
	while (x)
	{
		x = x->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ct);
		fclose(aug.file);
		free(aug.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	x = *hd;
	bus = x->next->n * x->n;
	x->next->n = bus;
	*hd = x->next;
	free(x);
}
