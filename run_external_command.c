#include "shell.h"

/**
 * run_external_command - run commands that are not built-in
 * @args: command and its arguments
 *
 * Return: void
 */
void run_external_command(char **args)
{
	if (access(args[0], F_OK) == -1)
	{
		char *path = NULL, *dir = NULL, *env_path = NULL, cmd[MAX_INPUT];
		int dir_len, args_0_len, i;

		for (i = 0; environ[i] != NULL; i++)
		{
			if (strncmp(environ[i], "PATH=", 5) == 0)
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

		path = strdup(env_path);
		dir = strtok(path, ":");
		args_0_len = strlen(args[0]);

		while (dir != NULL)
		{
			dir_len = strlen(dir);

			if (dir_len + args_0_len + 2 > MAX_INPUT)
			{
				write(STDERR_FILENO, "shell: command name too long\n", 29);
				free(path);
				return;
			}

			memcpy(cmd, dir, dir_len);
			cmd[dir_len] = '/';
			memcpy(cmd + dir_len + 1, args[0], args_0_len + 1);

			if (access(cmd, F_OK) == 0)
			{
				args[0] = strdup(cmd);
				free(path);
				execute_command(args);
				free(args[0]);
				return;
			}

			dir = strtok(NULL, ":");
		}

		if (args[0][0] != '/')
		{
			char cwd[MAX_INPUT], *cwd_ptr = getcwd(cwd, sizeof(cwd));

			if (cwd_ptr != NULL)
			{
				int cwd_len = strlen(cwd);

				if (cwd_len + 1 + args_0_len + 1 > MAX_INPUT)
				{
					write(STDERR_FILENO, "shell: command name too long\n", 29);
					free(path);
					return;
				}

				cmd[0] = '\0';
				memcpy(cmd, cwd, cwd_len);
				cmd[cwd_len] = '/';
				memcpy(cmd + cwd_len + 1, args[0], args_0_len + 1);

				if (access(cmd, F_OK) == 0)
				{
					args[0] = strdup(cmd);
					free(path);
					execute_command(args);
					free(args[0]);
					return;
				}
			}
		}

		write(STDERR_FILENO, "shell: command not found: ", 26);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, "\n", 1);

		free(path);
		return;
	}

	execute_command(args);
}
