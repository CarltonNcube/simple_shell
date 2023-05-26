#include "shell.h"

/**
 * _getline - reads a line from stdin into a dynamically allocated buffer
 * @lineptr: pointer to buffer
 * Return: number of characters read
 */
ssize_t _getline(char **lineptr)
{
	ssize_t size = 0;/* Current size of the buffer */
	ssize_t capacity = 0;/* Current capacity of the buffer */
	ssize_t bytesRead = 0;/* Number of bytes read from stdin */
	char c;
	char *temp = NULL;

	*lineptr = NULL;
	while (1)
	{
	/* Check if buffer capacity needs to be increased */
		if (size >= capacity)
		{
			capacity += 1024;
			temp = _realloc(*lineptr, capacity);
			if (temp == NULL)
			{
				free(*lineptr);
				return (-1);  /* Memory allocation failed */
			}
			*lineptr = temp;
		}
		/* Read a single character from stdin */
		bytesRead = read(STDIN_FILENO, &c, 1);
		if (bytesRead == -1)
		{
			free(*lineptr);
			return (-1);  /* Read error */
		}
		if (bytesRead == 0 || c == '\n')
		{
			(*lineptr)[size] = '\0';  /* Null-terminate the string */
			break;
		}
		(*lineptr)[size] = c;
		size++;
	}
	free(*lineptr);
	*lineptr = NULL;
	return (size);
}
