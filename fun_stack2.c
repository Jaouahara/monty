#include "monty.h"
/**
 * fun_add - add the top two elements of the stack
 * @hd: stack head
 * @ct: line_number
 * Return: void
*/
void fun_add(stack_t **hd, unsigned int ct)
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

/**
  *fun_nop- doesn't do anything
  *@hd: stack head
  *@ct: linenumber
  *Return: no return
 */
void fun_nop(stack_t **hd, unsigned int ct)
{
	(void) ct;
	(void) hd;
}
