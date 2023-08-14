#include "shell.h"

/**
 * tok - creates tokens from a passed string
 * @ptr: string to be passed
 *
 * Return: array of strings
 */

char **tok(char *ptr)
{
	char **args;
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
 * Return: 0(Success) else 1 on failure
 */

int simple_shell(char **env)
{
	pid_t pid;
	size_t inp_len = 0;
	ssize_t read;
	char *buf = NULL;
	int status;
	char **args;

	while (1)
	{
		printf("$ ");
		read = getline(&buf, &inp_len, stdin);
		if (read == -1)
		{
			perror("getline");
			free(buf);
			exit(EXIT_FAILURE);
		}
		if (buf[read - 1] == '\n')
			buf[read - 1] = '\0';
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			args = tok(buf);
			if (execvp(args[0], args) == -1)
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
