#include "shell.h"

/**
 * is_builtin_command - chech if command is builtin or not
 * @command: command to be checked
 * Return: 0 if true
 */
int is_builtin_command(char *command)
{
	return (_strcmp(command, "exit") == 0 || 
		_strcmp(command, "setenv") == 0 ||
		_strcmp(command, "unsetenv") == 0 ||
		_strcmp(command, "cd") == 0);
}
