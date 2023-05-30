#include "shell.h"

/**
 * get_current_directory - get current working directory
 * Return: current directory
 */
char *get_current_directory()
{
	char *cwd = NULL;
	size_t size = 256; /* Initial buffer size */

	while (1)
	{
		cwd = (char *)malloc(size);
		if (cwd == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		if (getcwd(cwd, size) != NULL)
			return (cwd);

		free(cwd);
		if(errno != ERANGE)
		{
			perror("getcwd");
			return (NULL);
		}
		size *= 2; /* Double the buffer size for next attempt */
	}
	return (NULL);
}
