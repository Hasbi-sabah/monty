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
	for (i = 0; str[i]; i++)
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
	if (!data->stack)
		new_node->next = NULL;
	else
	{
		new_node->next = data->stack;
		data->stack->prev = new_node;
	}
	data->stack = new_node;
}
void pop_top(data_t *data)
{
	stack_t *tmp;

	if (_len(data->stack) == 1)
	{
		free(data->stack);
	        data->stack = NULL;
	}
	else
	{
		tmp = data->stack->next->prev;
		free(tmp);
		data->stack->next->prev = NULL;
		data->stack = data->stack->next;
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
	for (i = 0, h = data->stack; h; h = h->next, i++)
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
	if (!data->stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", data->stack->n);
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
	if (!data->stack)
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

	(void) data;
	if (_len(data->stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->stack->n;
	data->stack->n = data->stack->next->n;
	data->stack->next->n = temp;
}

/**
 *
 *
 *
 */
void add(unsigned int line_number, data_t *data)
{
	int temp;

	(void) data;
	if (_len(data->stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->stack->n + data->stack->next->n;
	pop_top(data);
	pop_top(data);
	add_top(temp, data);
}
void sub(unsigned int line_number, data_t *data)
{
	int temp;

	(void) data;
	if (_len(data->stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->stack->n - data->stack->next->n;
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

	(void) data;
	if (_len(data->stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (data->stack->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->stack->next->n / data->stack->n;
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

	(void) data;
	if (_len(data->stack) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->stack->n * data->stack->next->n;
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

	(void) data;
	if (_len(data->stack) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	if (data->stack->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	temp = data->stack->next->n % data->stack->n;
	pop_top(data);
	pop_top(data);
	add_top(temp, data);
}
void pchar(unsigned int line_number, data_t *data)
{
	if (data->stack->n < 0 || data->stack->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	if (!data->stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		freeMemory(data, 1);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", data->stack->n);	
}
