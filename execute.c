#include "monty.h"
/**
* execute - function stack
* @ct: line_counter
* @file: poiner to monty file
* @cont: line content
* @stack: line stack
* Return: void
*/
int execute(char *cont, stack_t **stack, unsigned int ct, FILE *file)
{
	instruction_t opst[] = {
			       {"push", fun_push}, {"pall", fun_pall}, {"pint", fun_pint},
			       {"pop", fun_pop},
			       {"swap", fun_swap},
			       /**
				* {"add", fun_add},
				* {"nop", fun_nop},
				* {"sub", fun_sub},
				* {"div", fun_div},
				* {"mul", fun_mul},
				*/
			       {"queue", fun_queue},
			       {"stack", fun_stack},
			       {NULL, NULL}
			       };
	unsigned int i = 0;
	char *od;

	od = strtok(cont, " \n\t");
	if (od && od[0] == '#')
		return (0);
	aug.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && od)
	{
		if (strcmp(od, opst[i].opcode) == 0)
		{	opst[i].f(stack, ct);
			return (0);
		}
		i++;
	}
	if (od && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", ct, od);
		fclose(file);
		free(cont);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
