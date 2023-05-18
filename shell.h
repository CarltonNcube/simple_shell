#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_ARGS 10
#define MAX_INPUT 1024
#define BUFFER_SIZE 256

extern char **environ;

void sigint_handler(int sig);
void run_external_command(char **args);
void run_builtin_command(char **args);
int is_builtin_command(char *command);
int parse_command(char *input, char **args);
void execute_command(char **args);
int _getc(FILE *stream);
char *_strcat(char *destination, char *source);
int _strcmp(const char *string1, const char *string2);
char *_strdup(const char *str);
size_t _strlen(const char *str);
int _strncmp(const char *string1, const char *string2, size_t num);
size_t _strspn(const char *s, const char *accept);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcpy(char *dest, const char *src);
int _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t size);
char *_strtok(char *str, const char *delim);
size_t _strcspn(const char *s, const char *reject);
int _atoi(const char *str);
void handle_exit(char **args);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);

#endif /* SHELL.H */
