#include "shell.h"

/**
 * run_builtin_command - helper for executing buit-in commands
 * @args: command and its arguments
 * Return: void
 */
void run_builtin_command(char **args)
{
	if (_strcmp(args[0], "exit") == 0)/* Exit command */
	{
		exit(EXIT_SUCCESS);
	}
}
