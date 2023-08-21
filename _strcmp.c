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
	while (*str1 != '\0' || *str2 != '\0') 
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}

	return (0);
}

/**
 * _strlen - gets the length of a string
 * @str: string to be checked
 *
 * Return: the length of the string
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
