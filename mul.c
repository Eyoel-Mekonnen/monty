#include "monty.h"
/**
 * mul - mulitplies top two stack
 * @top: top node of stack
 * @line_number: number of lines
 *
 */
void mul(stack_t **top, unsigned int line_number)
{
	int value;
	stack_t *newNode;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(container.file);
		free(container.line);
		free(*top);
		exit(EXIT_FAILURE);
	}
	newNode = *top;
	value = (*top)->next->n * (*top)->n;
	newNode = (*top)->next;
	free(*top);
	*top = newNode;
	(*top)->n = value;
}
