#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_INPUT 100

void simple_shell(char **env);
char **tok(char *ptr);
void printenv(char **env);
int _strcmp(char *str1, char *str2);
void printbash(void);
int _strlen(char *str);
char *pathcheck(char *str);
void nonshell(char **env, char **av);
void execute_command(char **args, char **env);

#endif
