#include "shell.h"

/**
 * _strncmp - compare two strings
 * @string1: first string
 * @string2: second string
 * @num: maximum number of characters to compare
 * Return: 0 same length, difference otherwise
 */
int _strncmp(const char *string1, const char *string2, size_t num)
{
	size_t i;

	/* Iterrate over the strings char by char, up to n chars */
	for (i = 0; i < num; i++)
	{
		/* If chars differ, return the difference */
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);

		/* If string1 ends before string2 return negative value */
		if (string1[i] == '\0')
			return (-1);
	}

	/* If we reach end of strings, return 0 if equal */
	return (0);
}
