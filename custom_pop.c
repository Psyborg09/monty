#include "monty.h"
/**
 * custom_pop - removes the top element of the stack
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_pop(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}
	current_node = *stack_head;
	*stack_head = current_node->next;
	free(current_node);
}
