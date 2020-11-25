#include "shell.h"

/**
 * sigint_helper - handles the SIGINT signal
 * SIGINT is a terminal interrupt signal (ctrl + c)
 * @i: unused parameter
 * Return: Nothing
 */
void sigint_helper(__attribute__((__unused__)) int i)
{
	write(STDOUT_FILENO, "\n", 1);
	shell_prompt();
}
