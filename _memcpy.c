#include "shell.h"

/**
 * _memcpy - copy a block of memory from one location to another
 * @dest: destination address
 * @src: source of copy
 * @n: bytes of data from source buffer
 * Return: void
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *d = (char *)dest;
	const char *s = (const char *)src;

	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dest);
}
