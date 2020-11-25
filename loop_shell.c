#include "shell.h"

/**
 * shell_prompt - writes to stdout prompt string PS1
 * isatty tests whether fd ->file descriptor is associated
 * terminal device. The function evaluates if this is found to
 * be true
 * Return: Nothing
 */
void shell_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
 * loop_shell - known as Read-Eval-Print-Loop or REPL
 * the shell reads input, parses and executes it, then loops
 * to read next command and so on until command such as
 * exit, shutdown or reboot is entered
 * @line_cmd: arguments entered in the command line
 * @tokens: points to an array of pointers to strings
 * @status: equals to 1
 * Return: Nothing
 */
void loop_shell(char *line_cmd, char **tokens, int status)
{
	while (1)
	{
		signal(SIGINT, sigint_helper);
		shell_prompt();
		line_cmd = read_line();
		status = 1;

		if (!line_cmd)
		{
			exit(EXIT_SUCCESS);
		}

		if (f_strcmp(line_cmd, " ") == 0)
		{
			free(line_cmd);
			continue;
		}
		if (f_strcmp(line_cmd, "exit\n") == 0)
		{
			free(line_cmd);
			break;
		}
		free(line_cmd);
		tokens = tokenize_line(line_cmd);
		status = executor(tokens);
	}
}
