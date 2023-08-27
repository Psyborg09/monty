#include "monty.h"

/**
 * custom_rotate_right - rotates the stack to the bottom
 * @stack_head: stack head
 * @line_number: line_number (unused)
 * Return: no return
 */
void custom_rotate_right(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;

	(void) line_number;

	current_node = *stack_head;
	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	while (current_node->next)
	{
		current_node = current_node->next;
	}
	current_node->next = *stack_head;
	current_node->prev->next = NULL;
	current_node->prev = NULL;
	(*stack_head)->prev = current_node;
	(*stack_head) = current_node;
}
