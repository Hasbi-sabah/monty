#include "monty.h"

void dataInit( data_t *data, char **argv, char **cmd, stack_t *stack);

/**
 * main - monty interpreter
 *
 *
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char **cmd = NULL;
	data_t data;

	if (argc != 2)
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

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
