#include "shell.h"

/**
 * main - Entry point
 * @argc: unused argument count
 * @argv: unused argument vector
 * Return: 0 if successful
 */
int main(__attribute__((__unused__)) int argc, __attribute__((__unused__)) char *argv[])
{
	char pwd[1024];
	char PATH[1024];

	getcwd(pwd, sizeof(pwd)); /* present working directory */
	f_strcopy(PTH, PWD); /* find commands */
	f_strcat(PATH, "/shell_cmds/"); /* concatenate commands in directory with path to get full path */

	loop_shell();
	return (0);
}
