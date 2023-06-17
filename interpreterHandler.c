#include "monty.h"

void interpreter(data_t *data);

/**
 * interpreter - read the file and handle the commands
 *
 *
 */
void interpreter(data_t *data)
{
	int i, j, rd = 0, size = 0, fd = openFile(data);
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", NULL},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr}
	};
	int opSize = sizeof(ops) / sizeof(ops[0]);

	j = 1;
	while ((rd = _getLine(data, &size, fd)) != -1)
	{
		if (rd == 0)
			continue;
		/* Tokenize the lineptr*/
		data->cmd = _strtok(data->lineptr, DELIM, &data->cmdSize);

		/*check if the tokens > 0*/
		if (data->cmdSize > 0)
		{
			/*call functions */
			for (i = 0; i < opSize; i++)
			{
				if (data->cmd[0][0] == '#')
					break;
				if (!strcmp(ops[i].opcode, data->cmd[0]))
				{
					if (ops[i].f)
						ops[i].f(j, data);
					break;
				}
			}
			if (i == opSize)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", j, data->cmd[0]);
				freeMemory(data, 1);
				exit(EXIT_FAILURE);
			}
		}
		j++;
		freeMemory(data, 0);
	}
	  freeMemory(data, 1);
}
