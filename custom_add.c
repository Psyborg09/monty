#include "monty.h"
/**
 * custom_add - adds the top two elements of the stack.
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
*/
void custom_add(stack_t **stack_head, unsigned int line_number)
{
	stack_t *currentNode;
	int stack_length = 0, sum;

	for (currentNode = *stack_head; currentNode; currentNode = currentNode->next)
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
	currentNode = *stack_head;
	sum = currentNode->n + currentNode->next->n;
	currentNode->next->n = sum;
	*stack_head = currentNode->next;
	free(currentNode);
}
