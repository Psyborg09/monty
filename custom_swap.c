#include "monty.h"

/**
 * custom_swap - swaps the top two elements of the stack.
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_swap(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	int stack_length = 0, temp_value;

	current_node = *stack_head;
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}
	current_node = *stack_head;
	temp_value = current_node->n;
	current_node->n = current_node->next->n;
	current_node->next->n = temp_value;
}
