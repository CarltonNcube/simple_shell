#include "shell.h"

/**
 * _strspn - return length of initial segement of a string
 * @s: input string
 * @accept: characters interested in
 * Return: length of string
 */
size_t _strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	for (p = s; *p != '\0'; p++)
	{
		for (a = accept; *a != '\0'; a++)
		{
			if (*p == *a)
				break;
		}
		if (*a == '\0')
			return (count);
		else
			count++;
	}

	return (count);
}
