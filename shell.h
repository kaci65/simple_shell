#ifndef SHELL_H
#define SHELL_H

#define DELIMITERS " \n\r\t\a"

/* headers used */
#include <stdlib.h> /* free(), exit(), EXIT_SUCCESS, EXIT_FAILURE*/
#include <unistd.h> /* isatty */
#include <stdio.h> /* perror */
#include <sys/wait.h> /* waitpid */
#include <string.h> /* strtok() */

/* main shell functions */
int main (__attribute__((__unused__)) int ac, char *av[]);
void shell_prompt(void);
char *read_line(void);
void print_env (char **environ);
int forkd(char **str_args);
int err_msg(void);

/* helper functions/ lib functions */
int f_strcmp(char *s1, char *s2);
void free_doublegrid(char **grid);
int _strlen(char *s);
int f_putchar(char c);

/* environ prototype */
extern char **environ;

/* signal function */
void sigint_helper(__attribute__((__unused__)) int i);

#endif /* #ifndef SHELL_H */