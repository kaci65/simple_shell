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
 * main - start us off
 * @ac: argument counter
 * @av: argument vector
 * Read-Eval-Print-Loop or REPL
 * the shell reads input, parses and executes it, then loops
 * to read next command and so on until command such as
 * exit, shutdown or reboot is entered
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	char *line_cmd;
	char **tokenize;
	char *args;

	while (1)
	{
		signal(SIGINT, sigint_helper);
		shell_prompt();
		line_cmd = read_line();

		if (!line_cmd)
		{
			exit(EXIT_SUCCESS);
		}
		if (f_strcmp(line_cmd, "exit\n") == 0)
		{
			free(line_cmd);
			break;
		}
		if (line_cmd[0] != '\n')
		{
			tokenize = tokenize_line(line_cmd);
			if (*tokenize == NULL)
			{
				free(line_cmd);
				free(tokenize);
				continue;
			}
			if (1 == 1) /* checks if isatty equals 1 */
			{
				args = path(tokenize);
				forkd(args, tokenize);
				free(args);
			}
			else if (0 == 1)
			{
				forkd(tokenize[0], tokenize);
			}
			free(tokenize);
		}
		free(line_cmd);
	}
	return (0);
}
