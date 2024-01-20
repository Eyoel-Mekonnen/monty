#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @top: address of top stack
 * @line_number: the line number
 *
 */
void pint(stack_t **top, unsigned int line_number)
{
	
	container.count = line_number;
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(container.file);
		free_stack(*top);
		free(container.line);
		return;
	}
	else
		printf("%d\n",(*top)->n);
}
