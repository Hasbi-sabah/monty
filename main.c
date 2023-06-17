#include "monty.h"

void dataInit( data_t *data, char **argv, char **cmd, stack_t *stack);

/**
 * main - monty interpreter
 *
 *
 */
int main(int argc, char **argv)
{
	stack_t *stack;
	char **cmd;
	data_t data;

	/* initialize data */
	dataInit(&data, argv, cmd, stack);

	/* start the interpreter */
	interpreter(&data);

	return (0);
}

/**
 *
 *
 *
 */
void dataInit( data_t *data, char **argv, char **cmd, stack_t *stack)
{
	data->argv = argv;
	data->cmd = cmd;
	data->stack = stack;
	data->lineptr = NULL;
	data->cmdSize = 0;
}
