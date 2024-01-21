#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @top: top node address
 * @line_number: number of line
 *
 */
void rotl(stack_t **top, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;
	
	container.count = line_number;
	if (top == NULL || *top == NULL || (*top)->next == NULL)
		return;
	ptr1 = *top;
	ptr2 = (*top)->next;
	while (ptr1->next != NULL)
	{
		ptr1 = ptr1->next;
	}
	ptr1->next = *top;
	(*top)->prev = ptr1;
	(*top)->next = NULL;
	ptr2->prev = NULL;
	*top = ptr2;
}
