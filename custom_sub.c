#include "monty.h"

/**
 * custom_sub - subs the second top element from the top element of the stack
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_sub(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node, *temp_node;
	int difference, stack_length;

	current_node = *stack_head;
	stack_length = 0;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}
	current_node = *stack_head;
	difference = current_node->next->n - current_node->n;
	current_node->next->n = difference;
	temp_node = current_node->next;
	current_node->next = temp_node->next;
	if (temp_node->next != NULL)
	{
		temp_node->next->prev = current_node;
	}
	free(temp_node);
}
