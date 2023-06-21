#include "monty.h"

void stack(unsigned int line_number, data_t *data);
void queue(unsigned int line_number, data_t *data);
void rotl(unsigned int line_number, data_t *data);
void rotr(unsigned int line_number, data_t *data);
int _isint(char *str);

/**
 * stack - set the stack format to LIFO
 * @line_number: line number
 * @data: data
 */
void stack(unsigned int line_number, data_t *data)
{
	(void)line_number;
	data->stackMode = 0;
}

/**
 * queue - set the stack format to FIFO
 * @line_number: line number
 * @data: data
 */
void queue(unsigned int line_number, data_t *data)
{
	(void)line_number;
	data->stackMode = 1;
}

/**
 * _isint - check if the value pushed is an int
 * @str: value to check
 * Return: 0 (not int) | 1 (int)
 */
int _isint(char *str)
{
	int i, flag = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		flag = 1;
		str++;
	}
	for (i = 0; i < (int)strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	if (flag == 1 && i == 0)
		return (0);
	return (1);
}

/**
 * rotl - rotate the stack to the top
 * @line_number: line number
 * @data: data
 */
void rotl(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	if (data->stackSize < 2)
		return;


	h = data->tail_s;
	data->head_s->prev = h;
	h->next = data->head_s;
	data->head_s = data->head_s->next;
	data->tail_s = data->tail_s->next;
	h->next->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @line_number: line number
 * @data: data
 */
void rotr(unsigned int line_number, data_t *data)
{
	stack_t *h;

	(void) line_number;
	if (data->stackSize < 2)
		return;

	h = data->tail_s;
	data->tail_s = data->tail_s->prev;
	h->next = data->head_s;
	h->prev->next = NULL;
	h->prev = NULL;
	data->head_s = h;
}
