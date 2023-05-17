#include "shell.h"

/**
 * _strcat - concatenate two strings together
 * @source: source string
 * @destination: destination string
 * Return: concatenated string
 */
char *_strcat(char *destination, char *source)
{
	int dest_len = 0;
	int i = 0;

	/* Find end of destination string */
	while (destination[dest_len] != '\0')
		dest_len++;
	/* Copy the source string ot end of destination string */
	while (source[i] != '\0')
	{
		destination[dest_len + i] = source[i];
		i++;
	}
	/* Add null terminator to end of new string */
	destination[dest_len + i] = '\0';
	return (destination);
}
