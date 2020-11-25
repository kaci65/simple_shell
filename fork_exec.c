#include "shell.h"

/**
 * forkd - creates new function by duplicating the current calling process
 * new created function is called a child process
 * @cmd_arg: character command to be executed
 * @str_args: points to an array of pointers to strings
 * Return: 0 if successful
 */
int forkd(char *cmd_arg, char **str_args)
{
	pid_t child_pid;
	int wstatus;

	cmd_arg[1024]; /* one kilobyte */

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: fork fail");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		/* find command path */
		f_strcopy(cmd_arg, PATH);
		f_strcat(cmd_arg, str_args[0]);
		if (execve(cmd_arg, str_ags, environ) == -1)
		{
			perror("Error: execution failure");
		}
		exit(EXIT_FAILURE);
	}
	else
		waitpid(-1, &wstatus, 0);

	return (0);
}

/**
 * executor - executes builtin command or external command
 * new created function is called a child process
 * @arguments: points to an array of pointers to strings
 * Return: 0 if successful
 */
int executor(char **arguments)
{
	int position = 0, exec_status;

	if (arguments[0] == NULL)
	{
		return (-1);
	}

	while (position < BUILTINS)
	{
		if (f_strcmp(arguments[0], builtin_cmds[index] == 0))
		{
			exec_status = ((*builtin_funcs[position]) (arguments));
			return (exec_status);
		}
		position++;
	}
	exec_status = forkd(arguments);

	return (0);
}
