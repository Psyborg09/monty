#include "monty.h"
/**
 * custom_pint - prints the top element of the stack, followed by a new line
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_pint(stack_t **stack_head, unsigned int line_number)
{
		if (*stack_head == NULL)
		{
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
			fclose(bus.file);
			free(bus.content);
			freestack(*stack_head);
			exit(EXIT_FAILURE);
		}
		printf("%d\n", (*stack_head)->n);
}
