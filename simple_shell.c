#include "shell.h"

/**
 * pathcheck - checks if command begins with /bin/
 * @str: string to be checked
 *
 * Return: updated string
 */

char *pathcheck(char *str)
{
	char *path = "/bin/";
	char *copy = malloc(sizeof(char) * 100);
	int i = 0;
	int j = 0;

	while (path[i] != '\0')
	{
		copy[i] = path[i];
		i++;
	}
	i = _strlen(copy);
	while (str[j] != '\0')
	{
		if (str[j] != path[j])
		{
			copy[i] = str[j];
			i++;
		}
		j++;
	}
	copy[i] = '\0';

	return (copy);
}

/**
 * printbash - prints ($) to stdout using the write function
 */

void printbash(void)
{
	char *str = "($) ";

	write(1, str, 4);
}

/**
 * printenv - prints the current environment
 * @env: the environment to print
 */

void printenv(char **env)
{
	int i;
	int j;
	char *newline = "\n";

	for (i = 0; env[i] != NULL; i++)
	{
		j = _strlen(env[i]);
		write(1, env[i], j);
		write(1, newline, 2);
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
	if (access(token, X_OK) != 0)
	{
		args = NULL;
		return (args);
	}
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

void simple_shell(char **env)
{
	pid_t pid;
	size_t inp_len = 0;
	ssize_t read;
	char *buf = NULL, **args;
	int status;

	while (1)
	{
		printbash();
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
		buf = pathcheck(buf);
		args = tok(buf);
		if (args == NULL)
		{
			free(buf);
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
	rest
}
