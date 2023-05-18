#include "shell.h"

/**
 * sigint_handler - ignore signal input
 * @sig: signal number
 * Return: void
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 4);
	fflush(stdout);
}
