#include "monty.h"

void add(unsigned int line_number, data_t *data);
void sub(unsigned int line_number, data_t *data);
void divi(unsigned int line_number, data_t *data);
void mul(unsigned int line_number, data_t *data);
void mod(unsigned int line_number, data_t *data);

/**
 * add - add the top two element of the stack
 * @line_number: line number
 * @data: data
 */
void add(unsigned int line_number, data_t *data)
{
	int temp = 0;

	if (data->stackSize < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->head_s->n + data->head_s->next->n;
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
}

/**
 * sub - sub the top element of the stack from the second one
 * @line_number: line number
 * @data: data
 */
void sub(unsigned int line_number, data_t *data)
{
	int temp;

	if (data->stackSize < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->head_s->next->n - data->head_s->n;
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
}

/**
 * divi - divide the second top element of the stack by the first one
 * @line_number: line number
 * @data: data
 */
void divi(unsigned int line_number, data_t *data)
{
	int temp;

	if (data->stackSize < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (data->head_s->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->head_s->next->n / data->head_s->n;
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
}

/**
 * mul - multiply the top element of the stack by the second one
 * @line_number: line number
 * @data: data
 */
void mul(unsigned int line_number, data_t *data)
{
	int temp;

	if (data->stackSize < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->head_s->n * data->head_s->next->n;
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
}

/**
 * mod - the rest of divison of the second top element of the stack by
 * the first one
 * @line_number: line number
 * @data: data
 */
void mod(unsigned int line_number, data_t *data)
{
	int temp;

	if (data->stackSize < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	if (data->head_s->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->head_s->next->n % data->head_s->n;
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
}
