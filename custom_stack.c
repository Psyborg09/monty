#include "monty.h"

/**
 * custom_stack - changes the mode to stack (LIFO)
 * @stack_head: stack head
 * @line_number: line_number (unused)
 * Return: no return
 */
void custom_stack(stack_t **stack_head, unsigned int line_number)
{
	(void) stack_head;
	(void) line_number;
	bus.lifi = 0;
}
