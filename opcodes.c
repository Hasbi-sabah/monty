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
 *
 *
 *
 *
 */
void pall(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	/* check if stack format is LIFO or FIFO*/
	/*if (data->stackMode == 1)
		h = data->tail_s;
	else*/
	h = data->head_s;

	/*printf("h=[%d] t=[%d]\n", data->head_s->n, data->tail_s->n);*/
	while (h)
	{
		printf("%d\n", h->n);
		/*if (data->stackMode == 1)
			h = h->prev;
		else*/
		h = h->next;
	}
}

/**
 *
 *
 *
 *
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
	/* check if stack format is LIFO or FIFO*/
        if (data->stackMode == 1)
                h = data->tail_s;
        else
                h = data->head_s;
	printf("%d\n", h->n);
}

/**
 *
 *
 *
 *
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
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
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
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
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
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
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
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
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
	pop_top(data, 0);
	pop_top(data, 0);
	add_top(temp, data, 0);
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
 * rotl - rotate the stack to the left (top to bottom)
 *
 *
 */
void rotl(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	if (data->stackSize < 2)
		return;


	h = data->tail_s;
	data->head_s->prev = h;
	h->next = data->head_s;
	data->head_s = data->head_s->next;
	data->tail_s = data->tail_s->next;
	h->next->next = NULL;
}

/**
 *
 *
 *
 */
void rotr(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	if (data->stackSize < 2)
		return;

	h = data->tail_s;
	data->tail_s = data->tail_s->prev;
	h->next = data->head_s;
	h->prev->next = NULL;
	h->prev = NULL;
	data->head_s = h;
}

/**
 * stack - set the stack format to LIFO
 * @line_number: line number
 * @data: data
 */
void stack(unsigned int line_number, data_t *data)
{
	(void)line_number;
	data->stackMode = 0;
}

/**
 * queue - set the stack format to FIFO
 * @line_number: line number
 * @data: data
 */
void queue(unsigned int line_number, data_t *data)
{
        (void)line_number;
        data->stackMode = 1;
}
