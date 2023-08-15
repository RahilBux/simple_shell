#include "shell.h"

/**
 * printenv - prints the current environment
 * @env: the environment to print
 */

void printenv(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

/**
 * tok - creates tokens from a passed string
 * @ptr: string to be passed
 *
 * Return: array of strings
 */

char **tok(char *ptr)
{
	char **args = malloc(sizeof(char *) * 10);
	char *token;
	int argc = 0;

	token = strtok(ptr, " ");
	while (token != NULL)
	{
		args[argc] = token;
		token = strtok(NULL, " ");
		argc++;
	}
	args[argc] = NULL;
	return (args);
}

/**
 * simple_shell - creates a simple shell environment
 * @env: Environment to pass to execve
 *
 * Return: 0(Success)
 */

int simple_shell(char **env)
{
	pid_t pid;
	size_t inp_len = 0;
	ssize_t read;
	char *buf = NULL, **args;
	int status;

	while (1)
	{
		printf("($) ");
		read = getline(&buf, &inp_len, stdin);
		if (buf[read - 1] == '\n')
			buf[read - 1] = '\0';
		if (_strcmp(buf, "exit") == 0)
			break;
		if (_strcmp(buf, "env") == 0)
		{
			printenv(env);
			continue;
		}
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			args = tok(buf);
			if (execve(args[0], args, env) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	free(buf);
	return (0);
}
