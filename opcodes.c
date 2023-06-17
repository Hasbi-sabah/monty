#include "monty.h"

int _len(stack_t *h);
int _isint(char *str);
void push(stack_t **stack, unsigned int line_number, data_t *data);
void pall(stack_t **stack, unsigned int line_number, data_t *data);
void pint(stack_t **stack, unsigned int line_number, data_t *data);
void pop(stack_t **stack, unsigned int line_number, data_t *data);
void swap(stack_t **stack, unsigned int line_number, data_t *data);
void add(stack_t **stack, unsigned int line_number, data_t *data);
void sub(stack_t **stack, unsigned int line_number, data_t *data);
void divi(stack_t **stack, unsigned int line_number, data_t *data);
void mul(stack_t **stack, unsigned int line_number, data_t *data);
void mod(stack_t **stack, unsigned int line_number, data_t *data);
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
void add_top(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = n;
	if (!(*stack))
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
void pop_top(stack_t **stack)
{
	if (_len(*stack) == 1)
		(*stack) = NULL;
	else
	{
		(*stack)->next->prev = NULL;
		(*stack) = (*stack)->next;
	}
}
void push(stack_t **stack, unsigned int line_number, data_t *data)
{
	if (data->cmdSize < 2 || !_isint(data->cmd[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_top(stack, atoi(data->cmd[1]));
}

/**
 *
 *
 *
 *
 */
void pall(stack_t **stack, unsigned int line_number, data_t *data)
{
	stack_t *h;
	int i;

	(void) line_number;
	(void) data;
	for (i = 0, h = *stack; h; h = h->next, i++)
		printf("%d\n", h->n);
}

/**
 *
 *
 *
 *
 */
void pint(stack_t **stack, unsigned int line_number, data_t *data)
{
	(void) data;
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 *
 *
 *
 *
 */
void pop(stack_t **stack, unsigned int line_number, data_t *data)
{
	(void) data;
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop_top(stack);
}

/**
 *
 *
 *
 *
 */
void swap(stack_t **stack, unsigned int line_number, data_t *data)
{
	int temp;

	(void) data;
	if (_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 *
 *
 *
 */
void add(stack_t **stack, unsigned int line_number, data_t *data)
{
	int temp;

	(void) data;
	if (_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	pop_top(stack);
	pop_top(stack);
	add_top(stack, temp);
}
void sub(stack_t **stack, unsigned int line_number, data_t *data)
{
	int temp;

	(void) data;
	if (_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n - (*stack)->next->n;
	pop_top(stack);
	pop_top(stack);
	add_top(stack, temp);
}
void divi(stack_t **stack, unsigned int line_number, data_t *data)
{
	int temp;

	(void) data;
	if (_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n / (*stack)->n;
	pop_top(stack);
	pop_top(stack);
	add_top(stack, temp);
}
void mul(stack_t **stack, unsigned int line_number, data_t *data)
{
	int temp;

	(void) data;
	if (_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n * (*stack)->next->n;
	pop_top(stack);
	pop_top(stack);
	add_top(stack, temp);
}
void mod(stack_t **stack, unsigned int line_number, data_t *data)
{
	int temp;

	(void) data;
	if (_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n % (*stack)->n;
	pop_top(stack);
	pop_top(stack);
	add_top(stack, temp);
}
