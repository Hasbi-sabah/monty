#include "monty.h"

void interpreter(data_t *data);

/**
 * interpreter - read the file and handle the commands
 *
 *
 */
void interpreter(data_t *data)
{
	int i, rd = 0, size = 0, fd = openFile(data);
	char *lineptr = NULL;

	while ((rd = _getLine(data, &size, fd)) != -1)
		{
			if (rd == 0)
				continue;

			data->cmd = _strtok(data->lineptr, DELIM, &data->cmdSize);

			for (i = 0; i < data->cmdSize; i++)
				printf("%s\n", data->cmd[i]);
		}
}
