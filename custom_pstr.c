#include "monty.h"

/**
 * custom_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_pstr(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	(void) line_number;

	current_node = *stack_head;
	while (current_node)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}
