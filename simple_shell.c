#include "shell.h"

/**
 * simple_shell - creates a simple shell
 *
 * Return: 0 if success else 1
 */

int simple_shell(void)
{
	pid_t pid;
	size_t inp_len = 0;
	ssize_t read;
	char *buf = NULL;
	int status;

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
			char *token;
			char *args[1024];
			int argc = 0;

			token = strtok(buf, " ");
			while (token != NULL)
			{
				args[argc] = token;
				token = strtok(NULL, " ");
				argc++;
			}
			args[argc] = NULL;
	
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(buf);
	return (0);
}
