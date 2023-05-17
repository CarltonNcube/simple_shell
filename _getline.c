#include "shell.h"
/**
 * _getline - read an entire line from stream
 * @lineptr: buffer containing text
 * @n: pointer length of stream
 * @stream: input stream
 * Return: number of characters read
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t size = BUFFER_SIZE;
	char *line = malloc(size * sizeof(char));
	int c = EOF;
	size_t i = 0;
	char *new_line;

	if (*lineptr)
	{
		free(*lineptr);
		*lineptr = NULL;
		*n = 0;
	}
		if (!line)
	{
		return (-1);
	}
		while ((c = _getc(stream)) != EOF)
	{
		if (i >= size - 1)
		{
			size *= 2;
			new_line = _realloc(line, size * sizeof(char));
			if (!new_line)
			{
				free(line);
				return (-1);
			}
			line = new_line;
		}
		line[i++] = c;
		if (c == '\n')
		{
			break;
		}
	}
	if (i == 0)
	{
		free(line);
		return (-1);
	}
	line[i] = '\0';
	*lineptr = line;
	*n = size;
	return (i);
}
