#include "shell.h"

/**
 * parse_command - seperate arguments into individual strings
 * @input: pointer to arguments
 * @args: individual strings
 * Return: number of arguments in array
 */
int parse_command(char *input, char **args)
{
	int argc = 0;
	char *arg;

	arg = _strtok(input, " \t\n");
	while (arg != NULL && argc < (MAX_ARGS - 1))
	{
		args[argc++] = arg;
		arg = _strtok(NULL, " \t\n");
	}
	args[argc] = NULL;

	return (argc);
}
