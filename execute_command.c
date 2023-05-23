#include "shell.h"

/**
 * execute_command - take array of arguments and execute them
 * @args: pointer to arguments
 * Return: void
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char error_msg[MAX_INPUT];

	pid = fork();

	if (pid == 0) /* Child process */
	{
		execve(args[0], args, environ);
		/* If execve returns, it must have failed */
		_strcpy(error_msg, "shell: ");
		_strcat(error_msg, args[0]);
		_strcat(error_msg, ": ");
		/* _strcat(error_msg, strerror(errno)); */
		_strcat(error_msg, "\n");
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) /* Fork failed */
	{
		_strcpy(error_msg, "shell: fork: ");
		/* _strcat(error_msg, strerror(errno)); */
		_strcat(error_msg, "\n");
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
	}
	else /* Parent process */
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
