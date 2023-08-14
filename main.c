#include "shell.h"

/**
 * main - creates a simple shell environment
 * @ac: argument count
 * @av: Array of pointers to strings
 * @env: string of environment variables
 *
 * Return: 0(Success)
 */

int main(int ac, char **av, char **env)
{
	simple_shell(env);

	return (0);
}
