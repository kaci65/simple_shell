#include "shell.h"

/**
 * f_strcmp - compares two strings
 * @s1: compare with s2
 * @s2: compare with s1
 * Return: integer
 */
int f_strcmp(char *s1, char *s2)
{
	int i;
	int result;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] > s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		else if (s1[i] < s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
	}
	return (0);
}

/**
 * free_doublegrid - frees a double pointer
 * @grid: double pointer to be freed
 */

 void free_doublegrid(char **grid)
 {
	 int index;

	 for (index = 0; grid[index]; index++)
	 {
		 free(grid[index]);
	 }
	 free(grid);
 }

 /**
 * _strlen - returns the length of a string
 * @s: receives variable s location
 * Return: length of string of int
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * f_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 *
 * Desc: First parameter in the write function is the file
 * descriptor of where to
 * write the output, we use one for standard output
 * Second parameter is a null terminated character string of the
 * content to write. We give the address to our char c parameter
 * Last parameter is the number of bytes to write. We have one character
 * we want to write that is 1 byte so we put a 1 as the parameter
 */
int f_putchar(char c)
{
	return (write(1, &c, 1));
}