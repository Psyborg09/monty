#include "monty.h"
/**
 * custom_div - divides the top two elements of the stack.
 * @stack_head: stack head
 * @line_number: number of line
 * Return: void
*/
void custom_div(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	int stack_length = 0, quotient;

	for(current_node = *stack_head; current_node; current_node = current_node->next)
	{
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	quotient = current_node->next->n / current_node->n;
	current_node->next->n = quotient;
	*stack_head = current_node->next;
	free(current_node);
}
