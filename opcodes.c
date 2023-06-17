#include "monty.h"

void push(stack_t **stack, unsigned int line_number, char **cmd)
{
	if (!cmd[1] || )
	{
		dprintf(2,  
	}
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t h;
	int i;

	(void) line_number;
	for (i = 0, h = *stack; h; h = h->next, i++)
		printf("%d\n", h->n);
}
