#include "shell.h"

/**
 * print_env - prints the environment
 * @environ: variable pointing to an array
 * of pointers to strings called the "environment"
 * Return: 0 if successful
 */
void print_env(char **environ)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		f_putchar('\n');
	}
}
