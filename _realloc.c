#include "shell.h"

/**
 * _realloc - reallocate a block of memory
 * @ptr: pointer to previously allocated block
 * @size: new size in bytes of memory block
 * Return: void
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t old_size;

	if (!ptr)
	{
		return (malloc(size));
	}

	if (!size)
	{
		free(ptr);
		return (NULL);
	}

	old_size = *((size_t *)ptr - 1);
	new_ptr = malloc(size);

	if (!new_ptr)
	{
		return (NULL);
	}
	if (size > old_size)
	{
		size = old_size;
	}

	_memcpy(new_ptr, ptr, size);
	free(ptr);

	return (new_ptr);
}
