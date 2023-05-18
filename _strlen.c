#include "shell.h"

/**
 * _strlen - get string length
 * @str: input string
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
