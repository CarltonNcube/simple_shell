#include "shell.h"

/**
 * run_external_command - run commands that are not built in
 * @args: command and its arguments
 * Return: void
 */
void run_external_command(char **args)
{
	int i;

	if (access(args[0], F_OK) == -1)
	{
		char *path = NULL;
		char *dir = NULL;
		char *env_path = NULL;
		char cmd[MAX_INPUT];
		int dir_len, args_0_len;

		for (i = 0; environ[i] != NULL; i++)
		{
			if (_strncmp(environ[i], "PATH=", 5) == 0)
			{
				env_path = environ[i] + 5;
				break;
			}
		}
		if (env_path == NULL)
		{
			write(STDERR_FILENO, "shell: PATH variable not set\n", 30);
			return;
		}
		path = _strdup(env_path);
		dir = _strtok(path, ":");
		args_0_len = _strlen(args[0]);

		while (dir != NULL)
		{
			dir_len = _strlen(dir);
			if (dir_len + args_0_len + 2 > MAX_INPUT)
			{
				write(STDERR_FILENO, "shell: command name too long\n", 29);
				free(path);
				return;
			}
			_memcpy(cmd, dir, dir_len);
			cmd[dir_len] = '/';
			_memcpy(cmd + dir_len + 1, args[0], args_0_len + 1);
			if (access(cmd, F_OK) == 0)
			{
				args[0] = _strdup(cmd);
				free(path);
				execute_command(args);
				free(args[0]);
				return;
			}
			dir = _strtok(NULL, ":");
		}
		write(STDERR_FILENO, "shell: command not found: ", 26);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, "\n", 1);
		free(path);
		return;
	}
	execute_command(args);
}
