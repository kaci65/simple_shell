#include "shell.h"

/**
 * main - Entry point
 * @ac: unused argument count
 * @av: unused argument vector
 * Return: 0 if successful
 */
int main(__attribute__((__unused__)) int ac, __attribute__((__unused__)) char **av)
{
	char pwd[1024];
	char PATH[1024];

	getcwd(pwd, sizeof(pwd)); /* present working directory */
	f_strcopy(PTH, PWD); /* find commands */

	/* concatenate commands in directory with path to get full path */
	f_strcat(PATH, "/shell_cmds/");

	loop_shell();
	return (0);
}
