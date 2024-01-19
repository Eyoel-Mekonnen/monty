#include "monty.h"
/**
 * push - pushes to stack to the first node
 * @top: address of the first node
 * @line_number: number of lines read
 *
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return;
	newNode->n = container.value_passed;
	container.count = line_number;
	if (*top == NULL)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		*top = newNode;
	}
	else
	{
		(*top)->prev = newNode;
		newNode->next = *top;
		newNode->prev = NULL;
		*top = newNode;
	}
}
