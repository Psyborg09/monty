#include "monty.h"
/**
* execute - executes the opcode
* @stack_head: head linked list - stack
* @line_number: line_counter
* @monty_file: poiner to monty file
* @line_content: line content
* Return: no return
*/
int execute(char *line_content, stack_t **stack_head, unsigned int line_number, FILE *monty_file)
{
	instruction_t operations[] = {
				{"push", custom_push},
				{"pall", custom_pall},
				{"pint", custom_pint},
				{"pop", custom_pop},
				{"swap", custom_swap},
				{"add", custom_add},
				{"nop", custom_nop},
				{"sub", custom_sub},
				{"div", custom_div},
				{"mul", custom_mul},
				{"mod", custom_mod},
				{"pchar", custom_pchar},
				{"pstr", custom_pstr},
				{"rotl", custom_rotate_left},
				{"rotr", custom_rotate_right},
				{"queue", custom_queue},
				{"stack", custom_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(line_content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (operations[i].opcode && opcode)
	{
		if (strcmp(opcode, operations[i].opcode) == 0)
		{	operations[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcode && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(monty_file);
		free(line_content);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
