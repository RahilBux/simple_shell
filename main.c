#include "shell.h"

/**
 * main - Creates a simple shell environment
 * @ac: Argument count
 * @av: Array of pointers to string of arguments
 * @env: Array of strings to the environment
 *
 * Return: 0(Success)
 */

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	simple_shell(env);

	return (0);
}
