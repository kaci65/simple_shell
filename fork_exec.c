#include "shell.h"

/**
 * forkd - creates new function by duplicating the current calling process
 * new created function is called a child process
 * @str_args: points to an array of pointers to strings
 * Return: 0 if successful
 */
int forkd(char **str_args)
{
	pid_t child_pid;
	int wstatus;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(str_args[0], str_args, environ) == -1)
		{
			err_msg();
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&wstatus);
		}
	}
	return (0);
}
