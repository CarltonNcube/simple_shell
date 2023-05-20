#include "shell.h"

/**
 * _strcmp - compare two strings
 * @string1: first string
 * @string2: second string
 * Return: Difference between the strings
 */
int _strcmp(const char *string1, const char *string2)
{
	int i = 0;

	/* Compare characters of the two strings */
	while (string1[i] == string2[i])
	{
		/* If end is reached, strings are equal */
		if (string1[i] == '\0')
			return (0);
		i++;
	}

	/* Difference between the stringss */
	return (string1[i] - string2[i]);
}
