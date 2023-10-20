#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list
 * @n: number
 * @prev: pointe to the prev ele
 * @next: pointe to the next ele
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - contains global varibale.
 * @ourLf: is stack or queue
 * @fd: to descripe the file
 * @bfr: the text
 * @currt: current line
 * @arg: the secod para
 * @head: dbl linked ls
 */
typedef struct globals
{
	int ourLf;
	stack_t *head;
	FILE *fd;
	char *bfr;
	unsigned int currt;
	char  *arg;
} global_t;


/**
 * struct aug_s - represents an "augmented" data type
 * @arg:  pointer to a character array
 * @file: a file
 * @content: pointer to a character array
 * @lifi: integer representing a lifi value
 */
typedef struct aug_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  aug_t;
extern aug_t aug;

/**
 * struct instruction_s - linked list for opcode
 * @opcode: opcode
 * @f: handle opcod
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void fun_push(stack_t **hd, unsigned int ct);
void fun_pint(stack_t **hd, unsigned int ct);
void fun_pop(stack_t **hd, unsigned int ct);
void fun_swap(stack_t **hd, unsigned int ct);
int main(int argc, char *argv[]);
void free_stack(stack_t *hd);
void fun_queue(stack_t **hd, unsigned int ct);
void addqueue(stack_t **hd, int n);
int execute(char *cont, stack_t **stack, unsigned int ct, FILE *file);
void addnode(stack_t **head, int n);
void fun_stack(stack_t **hd, unsigned int ct);
void fun_pall(stack_t **hd, unsigned int ct);
ssize_t getline(char **cont, size_t *size, FILE *file);
void fun_add(stack_t **hd, unsigned int ct);
void fun_nop(stack_t **hd, unsigned int ct);
void fun_sub(stack_t **hd, unsigned int ct);
void fun_div(stack_t **hd, unsigned int ct);
void fun_mul(stack_t **hd, unsigned int ct);

#endif
