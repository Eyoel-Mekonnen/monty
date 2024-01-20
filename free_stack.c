#include "monty.h"
/**
 * free_stack - free allocated stack memory
 * @top: address of the pointer pointing to stack
 *
 */
void free_stack(stack_t *top)
{
	stack_t *node;

	node = top;
	while (top)
	{
		node = top->next;
		free(top);
		top = node;
	}
}
