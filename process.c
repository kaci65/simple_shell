#include "shell.h"

/**
 * _process - prints PATH when commands/arguments are entered
 * @args: points to an array of pointers to strings
 * Return: 0 if successful
 */
int _process(char **args)
{
	pid_t child;
	int status;

	if (child == 0)
	{
		if (execve(args[0], args, environ) < 0)
		{
			f_putstr("command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}
		else if (child < 0)
		{
			f_putstr("fork error\n");
			sleep(3);
		}
		else
			wait(&status);

		return (0);
	}
}
