#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct container_s - contains the argument and value
 * @argument: the argument that is read from the file
 * @value_passed: the integer value
 *
 * Descritption: argument and its value
 * for stack, queues, LIFO, FIFO
 */
typedef struct container_s
{
	char *argument;
	int value_passed;
	unsigned int count;
} container_t;
extern container_t container;
char **strtow(char *str);
void free_strtow(char **argv);
void free_stack(stack_t *top);
char *line_corrected(char *line);
void push(stack_t **top, unsigned int line_number);
int _strcmp1(char *s1, char *s2);
bool isinteger(char *str);
void pall(stack_t **top, unsigned int line_number);
#endif