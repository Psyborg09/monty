#include "monty.h"
/**
 * custom_rotate_left - rotates the stack to the top
 * @stack_head: stack head
 * @line_number: line_number (unused)
 * Return: no return
 */
void custom_rotate_left(stack_t **stack_head, unsigned int line_number)
{
	stack_t *tmp, *new_head;
	(void) line_number;

	tmp = *stack_head;
	new_head = (*stack_head)->next;
	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	new_head->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack_head;
	(*stack_head)->next = NULL;
	(*stack_head)->prev = tmp;
	(*stack_head) = new_head;
}
