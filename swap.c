#include "monty.h"
/**
 * swap - swaps two elements
 * @top: address of the top node
 * @line_number: number of lines addressed
 *
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	container.count = line_number;
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(container.file);
		free(container.line);
		exit(EXIT_FAILURE);
	}
	ptr1 = *top;
	ptr2 = (*top)->next;
	if (ptr2->next != NULL)
		ptr2->next->prev = ptr1;
	ptr1->prev = ptr2;
	ptr1->next = ptr2->next;
	ptr2->prev = ptr1->prev;
	ptr2->next = ptr1;
	*top = ptr2;
}
