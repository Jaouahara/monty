#include "monty.h"
aug_t aug = {NULL, NULL, NULL, 0};
/**
* main - function
* @argc: number of arg
* @argv: monty file
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	size_t size = 0;
	ssize_t re_line = 1;
	stack_t *stack = NULL;
	unsigned int ct = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	aug.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (re_line > 0)
	{
		cont = NULL;
		re_line = getline(&cont, &size, file);
		aug.content = cont;
		ct++;
		if (re_line > 0)
		{
			execute(cont, &stack, ct, file);
		}
		free(cont);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
