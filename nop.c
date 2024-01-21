#include "monty.h"
/**
 * nop - no operation
 * @top: address of the top node
 * @line_number: number of lines
 *
 */
void nop(stack_t **top, unsigned int line_number)
{
	container.count = line_number;
	(void)top;
}
