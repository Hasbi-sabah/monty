#include "monty.h"

void dataInit(data_t *data, char **argv);

/**
 * main - monty interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	data_t data;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* initialize data */
	dataInit(&data, argv);

	/* start the interpreter */
	interpreter(&data);

	return (0);
}

/**
 * dataInit - initialize data
 * @data: data struct
 * @argv: argument vector
 */
void dataInit(data_t *data, char **argv)
{
	data->argv = argv;
	data->cmd = NULL;
	data->head_s = NULL;
	data->tail_s = NULL;
	data->lineptr = NULL;
	data->stackSize = 0;
	data->stackMode = 0;
	data->cmdSize = 0;
}
