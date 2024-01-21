#include "monty.h"
/**
 * sub - subtracts top two elements
 * @top: address of the first node
 * @line: line number
 *
 */
void sub(stack_t **top, unsigned int line_number)
{
	int value;
	stack_t *newNode;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stackt too short\n", line_number);
		fclose(container.file);
		free(container.line);
		if (*top != NULL && (*top)->next == NULL)
			free(*top);
		exit(EXIT_FAILURE);
	}
	newNode = *top;
	value = (*top)->next->n - (*top)->n;
	newNode = (*top)->next;
	free(*top);
	*top = newNode;
	(*top)->n = value;
}
