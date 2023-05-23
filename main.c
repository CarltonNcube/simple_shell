#include "shell.h"

/**
 * main - entry point for program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, __attribute__((unused))char **argv)
{
	char *input = NULL;
	char *args[MAX_ARGS];
	int interactive;
	char *command = NULL, *seperator = NULL, *token = NULL;
	interactive = isatty(STDIN_FILENO);
	signal(SIGINT, sigint_handler);
	
	while (1)
	{
		if (interactive)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		if (_getline(&input) == -1)
			break;
		command = input;
		seperator = ";";
		token = _strtok(command, seperator);
		while (token != NULL)
		{
			if (_strcmp(token, seperator) == 0)
			{
				token = _strtok(NULL, seperator);
				continue;
			}
			argc = parse_command(token, args);
			if (argc > 0)
			{
				if (is_builtin_command(args[0]))
					run_builtin_command(args);
				else
					run_external_command(args);
			}
			token = _strtok(NULL, seperator);
		}
	}
	free(input);
	return (EXIT_SUCCESS);
}
