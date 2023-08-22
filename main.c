#include "shell.h"

/**
 * execute_command - executes a command in noninteractive shell
 * @args: command to execute
 * @env: environment to pass
 */

void execute_command(char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}

/**
 * main - Creates a simple shell environment
 * @argc: Argument count
 * @argv: Array of pointers to string of arguments
 * @env: Array of strings to the environment
 *
 * Return: 0(Success)
 */

int main(int argc, char *argv[], char **env)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t read_size;
	char *args[10];
	int arg_count;
	char *token;
	(void) argc;
	(void) argv;

	if (isatty(STDIN_FILENO))
	{
		simple_shell(env);
	}
	else
	{
		while ((read_size = getline(&line, &line_size, stdin)) != -1)
		{
			line[strcspn(line, "\n")] = '\0';

			token = strtok(line, " ");
			arg_count = 0;
			while (token != NULL && arg_count < 10 - 1)
			{
				args[arg_count] = token;
				arg_count++;
				token = strtok(NULL, " ");
			}
			args[arg_count] = NULL;

			if (arg_count > 0)
			{
				execute_command(args, env);
			}
		}
		free(line);
	}
	return (0);
}
