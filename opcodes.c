#include "monty.h"

int _len(stack_t *h);
int _isint(char *str);
void push(unsigned int line_number, data_t *data);
void pall(unsigned int line_number, data_t *data);
void pint(unsigned int line_number, data_t *data);
void pop(unsigned int line_number, data_t *data);
void swap(unsigned int line_number, data_t *data);
void add(unsigned int line_number, data_t *data);
void sub(unsigned int line_number, data_t *data);
void divi(unsigned int line_number, data_t *data);
void mul(unsigned int line_number, data_t *data);
void mod(unsigned int line_number, data_t *data);
void pchar(unsigned int line_number, data_t *data);
void pstr(unsigned int line_number, data_t *data);
void rotl(unsigned int line_number, data_t *data);
void rotr(unsigned int line_number, data_t *data);
/**
 *
 *
 *
 */
int _len(stack_t *h)
{
	int i;

	for (i = 0; h; h = h->next, i++)
		;
	return (i);
}

/**
 *
 *
 *
 *
 */
int _isint(char *str)
{
	int i;

	if (str[0] == '-')
		str++;
	for (i = 0; i < (int)strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 *
 *
 *
 *
 */
void add_top(int n, data_t *data)
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
	if (!data->head_s)
		new_node->next = NULL;
	else
	{
		new_node->next = data->head_s;
		data->head_s->prev = new_node;
	}
	if (data->stackSize == 0)
		data->tail_s = new_node;
	data->head_s = new_node;
	data->stackSize++;
}
void pop_top(data_t *data)
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
		tmp = data->head_s->next;
		data->head_s = data->head_s->next;
		free(tmp->prev);
		tmp->prev = NULL;
		data->stackSize--;

	}
}
void push(unsigned int line_number, data_t *data)
{
	if (data->cmdSize < 2 || !_isint(data->cmd[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	add_top(atoi(data->cmd[1]), data);
}

/**
 *
 *
 *
 *
 */
void pall(unsigned int line_number, data_t *data)
{
	stack_t *h;
	int i;

	(void) line_number;
	(void) data;
	for (i = 0, h = data->head_s; h; h = h->next, i++)
		printf("%d\n", h->n);
}

/**
 *
 *
 *
 *
 */
void pint(unsigned int line_number, data_t *data)
{
	(void) data;
	if (!data->head_s)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", data->head_s->n);
}

/**
 *
 *
 *
 *
 */
void pop(unsigned int line_number, data_t *data)
{
	(void) data;
	if (!data->head_s)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	pop_top(data);
}

/**
 *
 *
 *
 *
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

/**
 *
 *
 *
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
	pop_top(data);
	pop_top(data);
	add_top(temp, data);
}
void sub(unsigned int line_number, data_t *data)
{
	int temp;

	if (data->stackSize < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->head_s->n - data->head_s->next->n;
	pop_top(data);
	pop_top(data);
	add_top(temp, data);
}

/**
 *
 *
 *
 */
void divi(unsigned int line_number, data_t *data)
{
	int temp;

	if (data->stackSize < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (data->head_s->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->head_s->next->n / data->head_s->n;
	pop_top(data);
	pop_top(data);
	add_top(temp, data);
}

/**
 *
 *
 *
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
	pop_top(data);
	pop_top(data);
	add_top(temp, data);
}

/**
 *
 *
 *
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
	pop_top(data);
	pop_top(data);
	add_top(temp, data);
}

/**
 *
 *
 *
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
 *
 *
 *
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

/**
 *
 *
 *
 */
void rotl(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	if (data->stackSize < 2)
		return;
	for (h = data->head_s; h->next; h = h->next)
		;
	data->head_s->prev = h;
	h->next = data->head_s;
	data->head_s = data->head_s->next;
	h->next->next = NULL;
}
void rotr(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	if (data->stackSize < 2)
		return;
	for (h = data->head_s; h->next; h = h->next)
		;
	h->next = data->head_s;
	h->prev->next = NULL;
	h->prev = NULL;
	data->head_s = h;
}
