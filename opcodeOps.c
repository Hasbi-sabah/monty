#include "monty.h"

void push(unsigned int line_number, data_t *data);
void pall(unsigned int line_number, data_t *data);
void pint(unsigned int line_number, data_t *data);
void pchar(unsigned int line_number, data_t *data);
void pstr(unsigned int line_number, data_t *data);

/**
 * push - add an element to the stack
 * @line_number: line  number
 * @data: data
 */
void push(unsigned int line_number, data_t *data)
{
	if (data->cmdSize < 2 || !_isint(data->cmd[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	add_top(atoi(data->cmd[1]), data, data->stackMode);
}

/**
 * pall - print all elements in the stack
 * @line_number: line  number
 * @data: data
 */
void pall(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	h = data->head_s;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - print the value of the top element of the stack
 * @line_number: line  number
 * @data: data
 */
void pint(unsigned int line_number, data_t *data)
{
	stack_t *h;

	if (!data->head_s)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}

	h = data->head_s;
	printf("%d\n", h->n);
}

/**
 * pchar - print the char at the top of the stack
 * @line_number: line  number
 * @data: data
 */
void pchar(unsigned int line_number, data_t *data)
{
	if (!data->stackSize)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	if (data->head_s->n < 0 || data->head_s->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", data->head_s->n);
}

/**
 * pstr - print the string of the stack
 * @line_number: line  number
 * @data: data
 */
void pstr(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	for (h = data->head_s; h; h = h->next)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		printf("%c", h->n);
	}
	printf("\n");
}
