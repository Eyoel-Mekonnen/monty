#include "monty.h"
/**
 * add - adds the two top stack values
 * @top: first node address
 * @line_number: line number
 *
 */
void add(stack_t **top, unsigned int line_number)
{
	int value;
	stack_t *newNode;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	newNode = *top;
	value = (*top)->n + (*top)->next->n;
	newNode = (*top)->next;
	free(*top);
	*top = newNode;
	(*top)->n = value;
}
