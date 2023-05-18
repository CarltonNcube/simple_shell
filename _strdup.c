#include "shell.h"

/**
 * _strdup - duplicate a string
 * @str: input string
 * Return: pointer to new string
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}

	return (_memcpy(new_str, str, len));
}
