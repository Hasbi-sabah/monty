#include "monty.h"

void interpreter(data_t *data);
void opHandler(data_t *data, int j);

/**
 * interpreter - read the file and handle the commands
 *
 *
 */
void interpreter(data_t *data)
{
	int lnum, rd = 0, size = 0, fd = openFile(data);

	lnum = 1;
	while ((rd = _getLine(data, &size, fd)) != -1)
	{
		if (rd == 0)
			continue;
		/* Tokenize the lineptr*/
		data->cmd = _strtok(data->lineptr, DELIM, &data->cmdSize);

		/*check if the tokens > 0*/
		if (data->cmdSize > 0)
		{
			/*call opcode function handler */
		        opHandler(data, lnum);
		}
		lnum++;
		freeMemory(data, 0);
	}
	/*freeMemory(data, 1);*/
}

/**
 * opHandler - handle opcodes functions
 * @data: data
 * @lnum: line number
 */
void opHandler(data_t *data, int lnum)
{
	instruction_t ops[] = {
		{"add", add}, {"div", divi},
		{"mod", mod}, {"mul", mul},
		{"nop", NULL}, {"pall", pall},
		{"pchar", pchar}, {"pint", pint},
		{"pop", pop}, {"pstr", pstr},
		{"push", push}, {"queue", queue},
		{"rotl", rotl}, {"rotr", rotr},
		{"stack", stack}, {"sub", sub},
		{"swap", swap},
        };
	int mid, lo = 0, hi = sizeof(ops) / sizeof(ops[0]);

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (data->cmd[0][0] == '#')
			return;

		else if (!strcmp(ops[mid].opcode, data->cmd[0]))
		{
			if (ops[mid].f)
				ops[mid].f(lnum, data);
			return;
		}
		if (strcmp(ops[mid].opcode, data->cmd[0]) < 0)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, data->cmd[0]);
	freeMemory(data, 1);
	exit(EXIT_FAILURE);
}
