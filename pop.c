#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @top: top of the node
 * @line_number: line number
 *
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;

	container.count = line_number;
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(container.file);
		free(container.line);
		newNode = NULL;
		exit(EXIT_FAILURE);
	}
	newNode = *top;
	if ((*top)->next != NULL)
		newNode = (*top)->next;
	else
	{
		fclose(container.file);
		free(container.line);
		free(*top);
		exit(EXIT_SUCCESS);
	}
	free(*top);
	newNode->prev = NULL;
	*top = newNode;
}
