#include "shell.h"

/**
 * run_builtin_command - helper for executing buit-in commands
 * @args: command and its arguments
 * Return: void
 */
void run_builtin_command(char **args)
{
	int fd;

	if (_strcmp(args[0], "exit") == 0)/* Exit command */
	{
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		fd = _setenv(args[1], args[2]);
		if (fd == -1)
		{
			perror("setenv");
			exit(-1);
		}
		/* Set environment variable */
	}
}
