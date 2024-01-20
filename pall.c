#include "monty.h"
/**
 * pall - prints all elements of stack
 * @top: address of the first node
 * @line_number: number of lines counted
 *
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;

	if (*top == NULL)
	{
		return;
	}
	newNode = *top;
	container.count = line_number;
	while (newNode != NULL)
	{
		printf("%d\n", newNode->n);
		newNode = newNode->next;
	}
}
