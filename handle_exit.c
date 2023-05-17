#include "shell.h"

/**
 * handle_exit - handles the "exit" command
 * @args: arguments passed to the "exit" command
 * If no args provided, exits with exit code 0. If given
 * args, it parses it as integer and exits with that code
 */
void handle_exit(char **args)
{
	int exit_code;

	if (args[1] == NULL)
		exit(0);
	else
	{
		exit_code = _atoi(args[1]);
		exit(exit_code);
	}
}
