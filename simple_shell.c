#include "shell.h"

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
			printf("Error reading line\n");
			free(buf);
			return (1);
		}

		if (buf[read - 1] == '\n')
			buf[read - 1] = '\0';

		if (strcmp(buf, "exit") == 0)
		{
			printf("Exiting Shell...\n");
			free(buf);
			return (0);
		}

		pid = fork();

		if (pid < 0)
			printf("Error with fork\n");
		
		if (pid != 0)
		{
			wait(&status);
			continue;
		}
		else
		{
			if (execl(buf, buf, NULL) == -1)
				perror("./shell");
		}
	}
	free(buf);
	return (0);
}

