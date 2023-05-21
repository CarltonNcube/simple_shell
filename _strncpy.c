#include "shell.h"

/**
 * _strncpy - copy a string
 * @destination: destination of copy
 * @source: source of copy
 * @num: number of characters to be copied
 * Return: pointer to destination string
 */

char *_strncpy(char *destination, const char *source, size_t num)
{
	char *dest = destination;
	size_t i;

	for (i = 0; i < num && *source != '\0'; i++)
	{
		*dest++ = *source++;
		*dest = '\0';
	}
	for (; i < num; i++)
		*dest++ = '\0';

	return (destination);
}
