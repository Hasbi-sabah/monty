#include "monty.h"

void push(stack_t **stack, unsigned int line_number, data_t *data)
{
	if (!cmd[1] || _isint(cmd[1]))
	{
		dprintf(2, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->n = n;
	if (!(*head))
		new_node->next = NULL;
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}

}

void pall(stack_t **stack, unsigned int line_number, data_t *data)
{
	stack_t h;
	int i;

	(void) line_number;
	for (i = 0, h = *stack; h; h = h->next, i++)
		printf("%d\n", h->n);
}
