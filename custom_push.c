#include "monty.h"

/**
 * custom_push - add node to the stack
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void custom_push(stack_t **stack_head, unsigned int line_number)
{
        int value, index = 0, flag = 0;

        if (bus.arg)
        {
                if (bus.arg[0] == '-')
                        index++;
                for (; bus.arg[index] != '\0'; index++)
                {
                        if (bus.arg[index] > 57 || bus.arg[index] < 48)
                                flag = 1;
                }
                if (flag == 1)
                {
                        fprintf(stderr, "L%d: usage: push integer\n", line_number);
                        fclose(bus.file);
                        free(bus.content);
                        freestack(*stack_head);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(bus.file);
                free(bus.content);
                freestack(*stack_head);
                exit(EXIT_FAILURE);
        }
        value = atoi(bus.arg);
        if (bus.lifi == 0)
               custom_addnode(stack_head, value);
        else
		custom_addqueue(stack_head, value);
}
