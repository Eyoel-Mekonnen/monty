#include "monty.h"
/**
 * free_stack - free allocated stack memory
 * @top: address of the pointer pointing to stack
 *
 */
void free_stack(stack_t *top)
{
	if (top == NULL)
	{
		printf("Stack is Empty\n");
		return;
	}
	while (top->next != NULL) 
	{
		top = top->next;
		free(top->prev);
	}
	free(top);
	top = NULL;
}
