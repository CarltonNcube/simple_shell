#include "shell.h"

/**
 * _unsetenv - remove environment variable
 * @name: name of variable
 * Return: 0 on success, -1 on error
 */

int _unsetenv(const char *name)
{
	size_t name_len = _strlen(name);
	int i, env_var_index = 0;

	while (environ[env_var_index] != NULL)
	{
		if (_strncmp(environ[env_var_index], name, name_len) == 0 &&
				environ[env_var_index][name_len] == '=')
		{
		free(environ[env_var_index]);
			/* Shift remaining environment variables */
			for (i = env_var_index; environ[i] != NULL; ++i)
				environ[i] = environ[i + 1];
			return (0);
		}
		env_var_index++;
	}
	return (-1);
}
