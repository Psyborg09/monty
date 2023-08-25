#include "monty.h"
/**
 * custom_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
*/
void custom_mod(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	int stack_length = 0, remainder;

	current_node = *stack_head;
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current_node = *stack_head;
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}

	remainder = current_node->next->n % current_node->n;
        current_node->next->n = remainder;
	*stack_head = current_node->next;
	free(current_node);
}
