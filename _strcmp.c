#include "shell.h"

/**
 * _strcmp - compares two strings
 * @str1: First string
 * @str2: String to be compared
 *
 * Return: integer
 */

int _strcmp(char *str1, char *str2)
{
	int i;
	int cmp = 0;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			cmp++;
		}
	}

	return (cmp);
}

/**
 * _strlen - gets the length of a string
 * @str: string to be cheked
