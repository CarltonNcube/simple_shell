#include "shell.h"

/**
 * _strcpy - copy contents of source string to destination
 * @dest: copy destination
 * @src: source of copy
 * Return: pointer to beginnig of destination string
 */

char *_strcpy(char *dest, const char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest_start);
}
