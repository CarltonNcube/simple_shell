#include "shell.h"

/**
 * _memset - sets first n bytes of memoery pointed by s to c
 * @s: array of unsigned characters
 * @c: specified value
 * @n: bytes if memory
 * Return: void
 */
void _memset(void *s, int c, size_t n)
{
	size_t i;

	unsigned char *ptr = (unsigned char *)s;
	unsigned char value = (unsigned char)c;

	for (i = 0; i < n; i++)
		*(ptr + i) = value;
}
