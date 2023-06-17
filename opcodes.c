#include "monty.h"

int _len(stack_t *h);
int _isint(char *str);
void push(stack_t **stack, unsigned int line_number, data_t *data);
void pall(stack_t **stack, unsigned int line_number, data_t *data);
void pint(stack_t **stack, unsigned int line_number, data_t *data);
void pop(stack_t **stack, unsigned int line_number, data_t *data);
void swap(stack_t **stack, unsigned int line_number, data_t *data);

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
void push(stack_t **stack, unsigned int line_number, data_t *data)
{
	stack_t *new_node;

	if (data->cmdSize < 2 || !_isint(data->cmd[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = atoi(data->cmd[1]);
	if (!(*stack))
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
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
	if (_len(*stack) == 1)
		(*stack) = NULL;
	else
	{
		(*stack)->next->prev = NULL;
		(*stack) = (*stack)->next;
	}
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
