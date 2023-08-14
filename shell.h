#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

int simple_shell(char **env);
char **tok(char *ptr);
void printenv(char **env);

#endif
