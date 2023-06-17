#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>

#define DELIM " \t\n"
#define BUFFSIZE 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/*******data_struct***************/
/**
 * data - struct holding program's data
 * @argv: argument vector
 * @cmd: command line tokenized
 * @lineptr: line pointer
 * @stack: stack head
 * @cmdCounter: command count
 */
typedef struct data_t
{
        char **argv;
        char **cmd;
        stack_t *stack;
        char *lineptr;
        int cmdSize;
} data_t;

/*****************main*************/
void dataInit(data_t *data, char **argv, char **cmd, stack_t *stack);

/**************interpreter*********/
void interpreter(data_t *data);

/**************fileHandler*********/
int openFile(data_t *data);
void closeFile(data_t *data, int fd);

/***************_strtok************/
char **_strtok(char *str, const char *delim, int *size);
int countTok(char *str, const char *delim);
int tokLen(char *str, const char *delim, int index);
int isDelim(char c, const char *delim);

/**************getline************/
int _getLine(data_t *data, int *size, int stream);
int lineHelper(data_t *data, int rd, int i);

/*************MemoryHandler******/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, data_t *data);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, data_t *data);
void pall(stack_t **stack, unsigned int line_number, data_t *data);
void pint(stack_t **stack, unsigned int line_number, data_t *data);
void pop(stack_t **stack, unsigned int line_number, data_t *data);
void swap(stack_t **stack, unsigned int line_number, data_t *data);
void add(stack_t **stack, unsigned int line_number, data_t *data);
void sub(stack_t **stack, unsigned int line_number, data_t *data);
void divi(stack_t **stack, unsigned int line_number, data_t *data);
void mul(stack_t **stack, unsigned int line_number, data_t *data);

#endif
