#include "monty.h"
/**
 * push - pushes to stack to the first node
 * @top: address of the first node
 * @line_number: number of lines read
 *
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *newNode1;
	bool output;
	newNode1 = malloc(sizeof(stack_t));
	if (newNode1 == NULL)
		return;
	container.count = line_number;
	output = isinteger(container.integral);
	if (container.integral != NULL && isinteger(container.integral))
	{
		container.value_passed = atoi(container.integral);
		newNode1->n = container.value_passed;
	}
	else if (container.integral == NULL || output == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", container.count);
		fclose(container.file);
		if (*top != NULL)
			free_stack(*top);
		free(newNode1);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	if (*top == NULL)
	{
		newNode1->next = NULL;
		newNode1->prev = NULL;
		*top = newNode1;
	}
	else
	{
		(*top)->prev = newNode1;
		newNode1->next = *top;
		newNode1->prev = NULL;
		*top = newNode1;
	}
}
