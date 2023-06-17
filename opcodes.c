#include "monty.h"

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
void push(stack_t **stack, unsigned int line_number, data_t *data)
{
	stack_t *new_node;

	if (!data->cmdSize < 2 || _isint(data->cmd[1]))
	{
		dprintf(2, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed");
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

void pall(stack_t **stack, unsigned int line_number, data_t *data)
{
	stack_t *h;
	int i;

	(void) line_number;
	for (i = 0, h = *stack; h; h = h->next, i++)
		printf("%d\n", h->n);
}
