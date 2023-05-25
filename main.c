#include "shell.h"

/**
 * main - entry point for program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, __attribute__((unused)) char **argv)
{
	char input[MAX_ARGS], *start = NULL, *end = NULL;
	char c, *args[MAX_ARGS];
	int interactive, input_index;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		/* Reset input buffer and index */
		_memset(input, 0, sizeof(input));
		if (interactive)
			write(STDOUT_FILENO, "$ ", 2);
		/* Read input character by character */
		input_index = 0;
		while (read(STDIN_FILENO, &c, 1) == 1)
		{
			if (c == '\n')
				break;
			input[input_index++] = c;
		}
		/* Exit loop if reached end-of-file */
		if (input_index == 0)
		{
			if (!interactive)
				break;
			else
				continue;
		}
		/* Trim leading whitespace from the input */
		start = input;
		while (*start == ' ' || *start == '\t' || *start == '\n' ||
			*start == '\v' || *start == '\f' || *start == '\r')
			start++;

		/* Trim leading whitespace from the token */
		end = input + input_index - 1;
		while (end >= start && (*end == ' ' || *end == '\t'))
		{
			*end = '\0';
			end--;
		}
		/* Skip empty input lines */
		if (*start == '\0')
			continue;
		/* Parse and execute the command */
		argc = parse_command(start, args);
		if (argc > 0)
		{
			if (is_builtin_command(args[0]))
				run_builtin_command(args);
			else
				run_external_command(args);
		}
	}
	return (EXIT_SUCCESS);
}
