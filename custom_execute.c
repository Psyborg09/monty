#include "monty.h"
/**
* execute - executes the opcode
* @stack_head: head linked list - stack
* @linenum: line_counter
* @file: poiner to monty file
* @line: line content
* Return: no return
*/
int execute(char *line, stack_t **stack_head, unsigned int linenum, FILE *file)
{
	instruction_t operations[] = {{"push", custom_push},
		{"pall", custom_pall},
		{"pint", custom_pint},
		{"pop", custom_pop},
		{"swap", custom_swap},
		{"add", custom_add},
		{"nop", custom_nop},
		{"sub", custom_sub},
		{"div", custom_div}, {"mul", custom_mul}, {"mod", custom_mod},
				{"pchar", custom_pchar},
				{"pstr", custom_pstr},
				{"rotl", custom_rotate_left},
				{"rotr", custom_rotate_right},
				{"queue", custom_queue},
				{"stack", custom_stack},
				{NULL, NULL}
				};
	opcode = strtok(line_content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (operations[i].opcode && opcode)
	{
		if (strcmp(opcode, operations[i].opcode) == 0)
		{	operations[i].f(stack_head, line_number);
			return (0);
		}
		i++;
	}
	if (opcode && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(monty_file);
		free(line_content);
		freestack(*stack_head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
