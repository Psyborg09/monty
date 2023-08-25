#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void custom_add(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	int stack_length = 0, sum;

	for(current_node = *stack_head; current_node; current_node = current_node->next)
	{
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}
	current_node = *stack_head;
	sum = current_node->n + current_node->next->n;
	current_node->next->n = sum;
	*stack_head = current_node->next;
	free(current_node);
}
