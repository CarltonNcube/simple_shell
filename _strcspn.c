#include "shell.h"

/**
 * _strcspn - get length of initial substring
 * @s: string to search
 * @reject: charcters to reject
 * Return: length of initial substring
 */

size_t _strcspn(const char *s, const char *reject)
{
	size_t len = 0;
	const char *p;

	for (; *s != '\0'; s++, len++)
	{
		for (p = reject; *p != '\0'; p++)
		{
			if (*s == *p)
				return (len);
		}
	}
	return (len);
}
