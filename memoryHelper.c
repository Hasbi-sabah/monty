#include "monty.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

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
