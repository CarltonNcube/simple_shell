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
	ssize_t bytes_read;

	interactive = isatty(STDIN_FILENO);
	signal(SIGINT, sigint_handler);
	while (1)
	{
		/* Reset input buffer and index */
		_memset(input, 0, sizeof(input));
		if (interactive)
			write(STDOUT_FILENO, "$ ", 2);
		/* Read input character by character */
		input_index = 0;
		while ((bytes_read = read(STDIN_FILENO, &c, 1)) > 0)
		{
			if (c == '\n')
				break;
			input[input_index++] = c;
		}
		/* Exit loop if reached end-of-file */
		if (bytes_read <= 0)
		{
			if (bytes_read == 0)
			{
				if (interactive)
					write(STDOUT_FILENO, "\n", 1);
				break; /* End-of-file reached */
			}
			else if (errno == EINTR)
				continue; /* Signal interrupt, continue reading */
			else
			{
				perror("read");
				continue;
			}
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
