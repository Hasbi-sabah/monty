#include "monty.h"

int openFile(data_t *data);
void closeFile(data_t *data, int fd);

/**
 * openFile - open a file to read from
 * @data: data holder
 * Return: file descriptor
 */
int openFile(data_t *data)
{
	struct stat fileStat;
	int fd_src;

	fd_src = open(data->argv[1], O_RDONLY);

	if (fstat(fd_src, &fileStat) == -1 || fd_src == -1
	    || !S_ISREG(fileStat.st_mode))
	{
		fprintf(stderr, "Error: Can't open file %s\n", data->argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd_src);
}

/**
 * closeFile - close a file
 * @data: data holder
 * @fd: integer
 */
void closeFile(data_t *data, int fd)
{
	int stat;

	stat = close(fd);
	if (stat == -1)
	{
		/*fprintf(stderr, "Error: Can't close file %s\n", data->argv[1]);*/
		exit(EXIT_FAILURE);
	}
	(void)data;
}
