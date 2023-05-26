#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_ARGS 1024
#define BUFFER_SIZE 256

extern char **environ;

/* Function prototypes */
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
void _memset(void *s, int c, size_t n);
char *_strcpy(char *dest, const char *src);
ssize_t _getline(char **lineptr);
void *_realloc(void *ptr, size_t size);
char *_strtok(char *str, const char *delim);
size_t _strcspn(const char *s, const char *reject);
int _atoi(const char *str);
void handle_exit(char **args);
char *_strncpy(char *destination, const char *source, size_t num);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);
void change_directory(const char *path);
char *get_current_directory();

#endif /* SHELL.H */
