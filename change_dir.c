#include "shell.h"

/**
 * change_directory - change directory and update PWD and OLPWD
 * @path: specified directory
 * Return: void
 */

void change_directory(const char *path)
{
	char *old_pwd = _getenv("PWD");/* Current working directory */
	char *new_pwd = NULL;

	if (old_pwd)
		_setenv("OLDPWD", old_pwd);/* Update PWD with current */

	if (chdir(path) == 0)
	{
		new_pwd = get_current_directory();
		if (new_pwd)
			_setenv("PWD", new_pwd);
		else
			perror("cd");/* Print error message */
	}
	else
		perror("cd");/* Print error message */
}
