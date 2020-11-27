#include "shell.h"

int main (int ac, char *av[])
{
    char *line_cmd;

    while (1)
    {
        shell_prompt();
        line_cmd = read_line();

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
    }
    shell_prompt();
    return (0);
}

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