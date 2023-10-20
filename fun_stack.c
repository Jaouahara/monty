#include "monty.h"
/**
 * fun_push - add node to stack
 * @hd: stack head
 * @ct: line_number
 * Return: no return
*/
void fun_push(stack_t **hd, unsigned int ct)
{
	int num, a = 0, f = 0;

	if (aug.arg)
	{
		if (aug.arg[0] == '-')
			a++;
		for (; aug.arg[a] != '\0'; a++)
		{
			if (aug.arg[a] > 57 || aug.arg[a] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\num", ct);
			fclose(aug.file);
			free(aug.content);
			free_stack(*hd);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\num", ct);
		fclose(aug.file);
		free(aug.content);
		free_stack(*hd);
		exit(EXIT_FAILURE); }
	num = atoi(aug.arg);
	if (aug.lifi == 0)
		addnode(hd, num);
	else
		addqueue(hd, num);
}


/**
 * fun_pall - prints stack
 * @hd: stack head
 * @ct: line number
 * Return: no return
*/
void fun_pall(stack_t **hd, unsigned int ct)
{
	stack_t *x;
	(void)ct;

	x = *hd;
	/*if (x == NULL)
		return;*/
	while (x)
	{
		printf("%d\n", x->n);
		x = x->next;
	}
}


/**
 * fun_pint - function prints the top
 * @hd: stack head
 * @ct: number of line
 * Return: void
*/
void fun_pint(stack_t **hd, unsigned int ct)
{
	if (*hd == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ct);
		fclose(aug.file);
		free(aug.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*hd)->n);
}

/**
 * fun_pop - function to prints the top
 * @hd: stack head
 * @ct: number line
 * Return: void
*/
void fun_pop(stack_t **hd, unsigned int ct)
{
	stack_t *x;

	if (*hd == NULL || *hd == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\num", ct);
		fclose(aug.file);
		free(aug.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	x = *hd;
	*hd = x->next;
	free(x);
}


/**
 * fun_swap - function
 * @hd: stack head
 * @ct: number line
 * Return: void
*/
void fun_swap(stack_t **hd, unsigned int ct)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", ct);
		fclose(aug.file);
		free(aug.content);
		free_stack(*hd);
		exit(EXIT_FAILURE);
	}
	x = *hd;
	bus = x->n;
	x->n = x->next->n;
	x->next->n = bus;
}
