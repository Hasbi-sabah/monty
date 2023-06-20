#include "monty.h"

void add_top(int n, data_t *data, int mode);
void pop_top(data_t *data, int mode);
void pop(unsigned int line_number, data_t *data);
void swap(unsigned int line_number, data_t *data);

/**
 * add_top - add an element to the top of the stack
 * @n: element value
 * @data: data
 * @mode: stack format (stack/queue)
 */
void add_top(int n, data_t *data, int mode)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = n;
	if (data->stackSize == 0)
	{
		data->head_s = new_node;
		data->tail_s = new_node;
	}
	else
	{
		if (mode == 0)
		{
			new_node->next = data->head_s;
			data->head_s->prev = new_node;
			data->head_s = new_node;
		}
		else
		{
			data->tail_s->next = new_node;
			new_node->prev = data->tail_s;
			data->tail_s = new_node;
			data->tail_s->next = NULL;
		}
	}
	data->stackSize++;
}

/**
 * pop_top - pop the top of the stack
 * @data: data
 * @mode: stack format (stack/queue)
 */
void pop_top(data_t *data, int mode)
{
	stack_t *tmp;

	if (data->stackSize == 1)
	{
		free(data->head_s);
		data->head_s = NULL;
		data->tail_s = NULL;
		data->stackSize--;
	}
	else
	{
		/* check if stack format is LIFO or FIFO*/
		if (mode == 1)
		{
			tmp = data->tail_s;
			data->tail_s = tmp->prev;
			data->tail_s->next = NULL;
			free(tmp);
		}
		else
		{
			tmp = data->head_s->next;
			data->head_s = data->head_s->next;
			free(tmp->prev);
			tmp->prev = NULL;
		}
		data->stackSize--;
	}
}

/**
 * pop - pop an element of the stack
 * @line_number: line_number
 * @data: data
 */
void pop(unsigned int line_number, data_t *data)
{
	if (!data->head_s)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	pop_top(data, data->stackMode);
}

/**
 * swap - swap the top two elements of the stack
 * @line_number: line_number
 * @data: data
 */
void swap(unsigned int line_number, data_t *data)
{
	int temp;

	if (data->stackSize < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->head_s->n;
	data->head_s->n = data->head_s->next->n;
	data->head_s->next->n = temp;
}
