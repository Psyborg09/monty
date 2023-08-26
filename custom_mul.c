#include "monty.h"
/**
 * custom_mul - multiplies the top two elements of the stack.
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_mul(stack_t **stack_head, unsigned int line_number)
{
	stack_t *currentNode;
	int stack_length = 0, result;

	for (currentNode = *stack_head; currentNode; currentNode = currentNode->next)
	{
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}
	currentNode = *stack_head;
	result = currentNode->n * currentNode->next->n;
	currentNode->next->n = result;
	*stack_head = currentNode->next;
	free(currentNode);
}
