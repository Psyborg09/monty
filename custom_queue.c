#include "monty.h"

/**
 * custom_queue - changes the stack to a queue
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_queue(stack_t **stack_head, unsigned int line_number)
{
	(void)stack_head;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * custom_addqueue - add node to the tail of the queue
 * @stack_head: head of the stack
 * @new_value: new_value
 * Return: no return
 */
void custom_addqueue(stack_t **stack_head, int new_value)
{
	stack_t *new_node, *tail_node;

	tail_node = *stack_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
		}
	new_node->n = new_value;
	new_node->next = NULL;
	if (tail_node)
	{
		while (tail_node->next)
		tail_node = tail_node->next;
	}
	if (!tail_node)
	{
		*stack_head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail_node->next = new_node;
		new_node->prev = tail_node;
	}
}
