#include "shell.h"
/**
 * _setenv - change or add environment variable
 * @name: variable name
 * @value: value of variable
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value)
{
	int env_var_index;
	char *existing_value = _getenv(name);
	size_t name_len, value_len, new_env_var_len;
	char *new_env_var;

	if (existing_value != NULL)
		return (0);

	name_len = _strlen(name);
	value_len = _strlen(value);
	new_env_var_len = name_len + value_len + 2;
	new_env_var = (char *) malloc(new_env_var_len);
	if (new_env_var == NULL)
		return (-1);

	/* Copy name and value into new environment variable string */
	_strncpy(new_env_var, name, name_len);
	new_env_var[name_len] = '=';
	_strncpy(new_env_var + name_len +  1, value, value_len);
	new_env_var[new_env_var_len - 1] = '\0';

	/* Find location to insert/update environment variable */
	env_var_index = 0;
	while (environ[env_var_index] != NULL)
	{
		if (_strncmp(environ[env_var_index], name, name_len) == 0 &&
				environ[env_var_index][name_len] == '=')
		{
			/* Variable already exists, update it */
			free(new_env_var);
			return (0);
		}
		env_var_index++;
	}
	/* Add new environmeny variable to the end of list */
	environ[env_var_index] = new_env_var;
	environ[env_var_index + 1] = NULL;
	return (0);
}
