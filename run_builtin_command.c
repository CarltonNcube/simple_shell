#include "shell.h"

/**
 * run_builtin_command - helper for executing buit-in commands
 * @args: command and its arguments
 * Return: void
 */
void run_builtin_command(char **args)
{
	if (_strcmp(args[0], "exit") == 0) /* Exit command */
		handle_exit(args);
	else if (_strcmp(args[0], "cd") == 0) /* CD command */
	{
		if (args[1] == NULL || _strcmp(args[1], "~") == 0)
		{
			/* Change to HOME directory */
			char *home_dir = _getenv("HOME");
			change_directory(home_dir);
		}
		else if (_strcmp(args[1], "-") == 0)
		{
			/* Change to previous directory */
			char *prev_dir = _getenv("OLDPWD");
			change_directory(prev_dir);
		}
		else /* Change to specified directory */
			change_directory(args[1]);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL)
			perror("setenv: invalid arguments");
		else
		{
			if (_setenv(args[1], args[2]) != 0)
				perror("setenv: failed to set environment variable");
		}
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL)
			perror("unsetenv: invalid arguments");
		else
		{
			if (_unsetenv(args[1]) != 0)
				perror("unsetenv: failed to unset environment variable");
		}
	}
}
