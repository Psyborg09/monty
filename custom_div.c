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

	for (currentNode = *stack_head; currentNode; currentNode = currentNode->next)
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
	currentNode = *stack_head;

	if (currentNode->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}
	quotient = currentNode->next->n / currentNode->n;
	currentNode->next->n = quotient;
	*stack_head = currentNode->next;
	free(currentNode);
}
