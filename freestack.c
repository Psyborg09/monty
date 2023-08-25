#include "monty.h"
/**
* freestack - frees a doubly linked list
* @stack_head: head of the stack
*/
void freestack(stack_t *stack_head)
{
	stack_t *current_node;

	for (current_node = stack_head; current_node; current_node = stack_head)
	{
		stack_head = stack_head->next;
		free(current_node);
	}
}
