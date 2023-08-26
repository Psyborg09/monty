#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *monty_file;
	size_t line_size = 0;
	ssize_t read_line = 1;
	stack_t *stack_head = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	bus.file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line_content = NULL;
		read_line = getline(&line_content, &line_size, monty_file);
		bus.content = line_content;
		line_number++;
		if (read_line > 0)
		{
			execute(line_content, &stack_head, line_number, monty_file);
		}
		free(line_content);
	}
	freestack(stack_head);
	fclose(monty_file);
return (0);
}
