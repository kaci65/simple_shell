#include "shell.h"

/**
 * err_msg - output error message
 * Return: 0 if successful
 */
int err_msg(void)
{
	write(STDOUT_FILENO, "function fail", 12);
	f_putchar('\n');

	return (0);
}
