#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @monty_file: pointer to monty file
 * @line_content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values throughout the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack_head, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void custom_push(stack_t **stack_head, unsigned int line_number);
void custom_pall(stack_t **stack_head, unsigned int line_number);
void custom_pint(stack_t **stack_head, unsigned int line_number);
void freestack(stack_t *stack_head);
int execute(char *line, stack_t **stack_head, unsigned int linenum, FILE *file);
void custom_pop(stack_t **stack_head, unsigned int line_number);
void custom_swap(stack_t **stack_head, unsigned int line_number);

void custom_add(stack_t **stack_head, unsigned int line_number);

void custom_nop(stack_t **stack_head, unsigned int line_number);
void custom_sub(stack_t **stack_head, unsigned int line_number);

void custom_div(stack_t **stack_head, unsigned int line_number);

void custom_mul(stack_t **stack_head, unsigned int line_number);

void custom_mod(stack_t **stack_head, unsigned int line_number);
void custom_pchar(stack_t **stack_head, unsigned int line_number);
void custom_pstr(stack_t **stack_head, unsigned int line_number);

void custom_rotate_left(stack_t **stack_head,  __attribute__((unused)) unsigned int line_number);
void custom_rotate_right(stack_t **stack_head, __attribute__((unused)) unsigned int line_number);
void custom_addnode(stack_t **stack_head, int new_value);
void custom_addqueue(stack_t **stack_head, int new_value);
void custom_queue(stack_t **stack_head, unsigned int line_number);
void custom_queue(stack_t **stack_head, unsigned int line_number);
void custom_stack(stack_t **stack_head, __attribute__((unused)) unsigned int line_number);
extern bus_t bus = {NULL, NULL, NULL, 0};
extern unsigned int i = 0;
extern char *opcode;
#endif

