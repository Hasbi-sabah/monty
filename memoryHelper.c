#include "monty.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freeMemory(data_t *data, int end);

/**
 * _realloc - reallocate a memory block
 * @ptr: prev pointer
 * @old_size: prev size
 * @new_size: new size
 * Return: new pointer | NULL (failed)
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *cp = ptr;
	unsigned int i, min;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	min = old_size < new_size ? old_size : new_size;

	p = malloc(new_size);
	if (p == NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size != old_size && ptr != NULL)
	{
		for (i = 0; i < min; i++)
			p[i] = cp[i];
		free(ptr);
	}

	return (p);
}

/**
 * freeMemory - free allocated data
 * @data: data
 * @end: if the program is about to exit end = 1 to free stack
 */
void freeMemory(data_t *data, int end)
{
	int i;
	stack_t *tmp;

	free(data->lineptr);
	data->lineptr = NULL;

	for (i = 0; i < data->cmdSize; i++)
		free(data->cmd[i]);
	free(data->cmd);
	data->cmd = NULL;

	if (end == 1)
	{
		while (data->head_s != NULL)
		{
			tmp = data->head_s->next;
			free(data->head_s);
			data->head_s = NULL;
			if (tmp != NULL)
				data->head_s = tmp;
		}
		data->head_s = NULL;
	}
}
