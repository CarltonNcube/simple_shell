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
	size_t input_size = 0;
	char *args[MAX_ARGS];
	int interactive;

	interactive = isatty(STDIN_FILENO);
	signal(SIGINT, sigint_handler);

	while (1)
	{
		if (interactive)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		if (_getline(&input, &input_size, stdin) == -1)
			break;

		argc = parse_command(input, args);

		if (argc > 0)
		{
			if (_strcmp(args[0], "exit") == 0)
				handle_exit(args);
			else if (is_builtin_command(args[0]))
				run_builtin_command(args);
			else
				run_external_command(args);
		}
	}
	free(input);

	return (EXIT_SUCCESS);
}
