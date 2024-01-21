#include "monty.h"
/**
 * pstr - prints the string starting at the top of stack
 * @top: top of the stack
 * @line_number: number of lines
 *
 */
void pstr(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;

	if (*top == NULL)
	{
		printf("\n");
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	newNode = *top;
	while (newNode != NULL)
	{
		if (newNode->n > 0 && newNode->n < 128)
		{
			printf("%c", newNode->n);
		}
		else if (newNode->n == 0)
		{
			break;
		}
		else
		{
			fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
			fclose(container.file);
			free(container.line);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
		newNode = newNode->next;
	}
	printf("\n");
}
