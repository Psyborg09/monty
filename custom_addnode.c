#include "monty.h"
/**
 * custom_addnode - add node to the head stack
 * @stack_head: head of the stack
 * @new_value: new_value
 * Return: void
*/
void custom_addnode(stack_t **stack_head, int new_value)
{

	stack_t *new_node, *current_node;

	current_node = *stack_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (current_node)
		current_node->prev = new_node;
	new_node->n = new_value;
	new_node->next = *stack_head;
	new_node->prev = NULL;
	*stack_head = new_node;
}
