#include "monty.h"
/**
 * rotr - rotates the stack to the bottom.
 * @top: address of the first node
 * @line_number: line number count
 */
void rotr(stack_t **top, unsigned int line_number)
{
	stack_t *newNode;
	
	container.count = line_number;
	if (top == NULL || *top == NULL || (*top)->next == NULL)
		return;
	newNode = *top;
	while (newNode->next != NULL)
	{
		newNode = newNode->next;
	}
	newNode->prev->next = NULL;
	(*top)->prev = newNode;
	newNode->next = *top;
	newNode->prev = NULL;
	*top = newNode;
}
