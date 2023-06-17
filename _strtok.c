#include "monty.h"

char **_strtok(char *str, const char *delim, int *size);
int countTok(char *str, const char *delim);
int tokLen(char *str, const char *delim, int index);
int isDelim(char c, const char *delim);

/**
 * _strtok - tokenize a string
 * @str: string
 * @delim: delimiter
 * @size: size
 * Return: Array of tokens
 */
char **_strtok(char *str, const char *delim, int *size)
{
	char **arrtok;
	int i, j = 0, k, toklen = 0;

	if (str == NULL || delim == NULL || str[0] == '\0')
		return (NULL);
	*size = countTok(str, delim);
	if (*size == 0)
		return (NULL);
	arrtok = malloc(sizeof(char *) * (*size + 1));
	if (arrtok == NULL)
		return (NULL);
	for (i = 0; i < *size; i++)
	{
		while (isDelim(str[j], delim))
			j++;

		toklen = tokLen(str, delim, j);
		arrtok[i] = malloc(sizeof(char) * (toklen + 1));
		if (arrtok[i] == NULL)
		{
			/*freeSarray(arrtok, *size);*/
			return (NULL);
		}

		for (k = 0; k < toklen; k++)
		{
			arrtok[i][k] = str[j];
			j++;
		}
		arrtok[i][k] = '\0';
	} arrtok[i] = NULL;
	return (arrtok);
}

/**
 * countTok - counts number of tokens
 * @str: tokens holder
 * @delim: delimiter
 * Return: number of tokens
 */
int countTok(char *str, const char *delim)
{
	int i, count = 0;

	if (str == NULL || delim == NULL)
		return (0);
	for (i = 0; i < strlen(str); i++)
	{
		if (!isDelim(str[i], delim))
		{
			count++;
			i += tokLen(str, delim, i);
		}
	}
	return (count);
}
/**
 * tokLen - calculate the length of the token
 * @str: string
 * @delim: delimiter
 * @index: index
 * Return: integer
 */
int tokLen(char *str, const char *delim, int index)
{
	int len;

	for (len = 0; str[index + len] && str[index + len] != '\n'; len++)
	{
		if (isDelim(str[index + len], delim))
		{
			break;
		}
	}
	return (len);
}

/**
 * isDelim - check if the character is equalt to a delimiter
 * @c: character to check
 * @delim: delimiter(s)
 * Return: 1 (is delimiter) | 0 (not delimieter)
 */
int isDelim(char c, const char *delim)
{
	int i;

	for (i = 0; i < strlen(delim); i++)
	{
		if (c == delim[i])
			return (1);
	}

	return (0);
}
