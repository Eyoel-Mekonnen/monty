#include "monty.h"
/**
 * mod - finds modulo
 * @top: top address of the stack
 * @line_number: line number 
 *
 */
void mod(stack_t **top, unsigned int line_number)
{
	int value;
	stack_t *newNode;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(container.file);
		free(container.line);
		free(*top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(container.file);
		free(container.line);
		free(*top);
		exit(EXIT_FAILURE);
	}
	newNode = *top;
	value = (*top)->next->n % (*top)->n;
	newNode = (*top)->next;
	free(*top);
	*top = newNode;
	(*top)->n = value;
}
