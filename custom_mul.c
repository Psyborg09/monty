#include "monty.h"
/**
 * custom_mul - multiplies the top two elements of the stack.
 * @stack_head: stack head
 * @line_number line_numbe
 * 
 * Return: no return
 */
void custom_mul(stack_t **stack_head, unsigned int line_number)
{
        stack_t *current_node;
        int stack_length = 0, result;

        for (current_node = *stack_head; current_node; current_node = current_node->next)
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

        current_node = *stack_head;
        result = current_node->n * current_node->next->n;
        current_node->next->n = result;
        *stack_head = current_node->next;
        free(current_node);
}
