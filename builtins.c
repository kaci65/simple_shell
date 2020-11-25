#include "shell.h"
#define BUILTINS 2 /*number of builtins */

char *builtin_cmds[] = {
  "exit",
    "pwd"
};

/*
 * Function:  shell_cd
 * -------------------
 *  changes current working directory
 *
 * args: arguments to the cd command, will consider only the first argument after the command name
 */
/**
 * pwd_cmd - shows preset working directory
 * @arguments: to the command pwd
 * Return: 0 if successful
 */
int pwd_cmd(char **arguments)
{
  f_putstr("%s\n", pwd);
  return (0);
}

/**
 * exit_cmd - exits shell
 * @arguments: to the command exit
 * Return: 0 if successful
 */
int exit_cmd(char **arguments)
{
  char **argv;

  argv = arguments;
  return (0);
}

/**
 * builtin functions
 */
int (*builtin_funcs[]) (char **) = {
  &pwd_cmd,
    &exit_cmd
};

/**
 * curr_env - prints the current environment
 * @envp: points to an array of pointers to strings
 * It functions similar to environ
 */
void curr_env(int argc, char *argv[], char *envp[])
{
  int index;
     
  for (index = 0; envp[index] != NULL; index++)
    {
      printf("\n%s", envp[index]);
    }
}
