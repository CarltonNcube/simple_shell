#include "shell.h"

/**
 * _strtok - tokenize a string
 * @str: string to tokenize
 * @delim: delimeter characters
 * Return: pointer to next token
 */
char *_strtok(char *str, const char *delim)
{
	static char *saveptr;
	char *token;

	if (str != NULL)
		saveptr = str;
	else if (*saveptr == '\0')
		return (NULL);

	saveptr += _strspn(saveptr, delim);

	if (*saveptr == '\0')
		return (NULL);

	token = saveptr;
	saveptr += _strcspn(saveptr, delim);

	if (*saveptr != '\0')
	{
		*saveptr = '\0';
		saveptr++;
	}

	return (token);
}
