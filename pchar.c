#include "monty.h"
/**
 * pchar - prints char at the top of stack
 * @top: address of the first node
 * @line_number: number of line
 *
 */
void pchar(stack_t **top, unsigned int line_number)
{
	int i;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	i = (*top)->n;
	if (i >= 0 && i <= 128)
	{
		printf("%c\n", (*top)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	}
}
