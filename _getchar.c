#include "shell.h"

/**
 * _getc - read a char from file stream
 * @stream: file stream
 * Return: integer value of char
 */
int _getc(FILE *stream)
{
	char c;
	ssize_t n = read(fileno(stream), &c, 1);

	if (n == -1)
	{
		return (EOF);
	}
	else
	{
		return ((int) c);
	}
}
