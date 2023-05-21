#include "shell.h"

/**
 * _getenv - get environment variable
 * @name: name of variable
 * Return: pointer to variable name
 */
char *_getenv(const char *name)
{
	char **env = NULL;

	size_t name_len = _strlen(name);

	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (&((*env)[name_len + 1]));
	}
	return (NULL);
}
