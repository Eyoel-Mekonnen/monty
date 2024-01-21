#include "monty.h"
/**
 * div - divides the two numbers
 * @top: top node
 * @line_number: line number is printed
 *
 */
void divi(stack_t **top, unsigned int line_number)
{
	int value;
	stack_t *newNode;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	newNode = *top;
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(container.file);
		free(container.line);
		free(*top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->next->n / (*top)->n;
	newNode = (*top)->next;
	free(*top);
	*top = newNode;
	(*top)->n = value;
}
