#include "shell.h"

/**
 * err_msg - output error message
 * Return: 0 if successful
 */
int err_msg(void)
{
    write(STDOUT_FILENO, "execve failure", 3);
    f_putchar("\n");

    return (0);
}