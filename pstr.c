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

	newNode = *top;
	container.count = line_number;
	while (newNode != NULL)
	{
		if (newNode->n > 0 && newNode->n < 128)
		{
			printf("%c", newNode->n);
		}
		else
		{
			break;
		}
		newNode = newNode->next;
	}
	printf("\n");
}
