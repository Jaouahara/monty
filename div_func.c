#include "monty.h"

/**
 * fun_div - div the second ele bt first
 * @hd: stack head
 * @ct: line number
 * Return: void
 */
void fun_div(stack_t **hd, unsigned int ct)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", ct);
		fclose(aug.file);
		free(aug.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	x = *hd;
	if (x->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ct);
		fclose(aug.file);
		free(aug.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	bus = x->next->n / x->n;
	x->next->n = bus;
	*hd = x->next;
	free(x);
}
