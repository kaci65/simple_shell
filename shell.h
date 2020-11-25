#ifndef SHELL_H
#define SHELL_H

/* header files */
#include <stdlib.h> /* free(), exit(), EXIT_SUCCESS, EXIT_FAILURE*/
#include <unistd.h> /* execve, fork(), pid_t, isatty */
#include <stdio.h> /*perror(), stderr() */
#include <sys/wait.h> /* waitpid */
#include <string.h> /* strtok() */

/* my library functions */
int f_strcmp(char *s1, char *s2);
char *f_strcopy(char *dest, char *src);
char *f_strcat(char *dest, char *src);
int f_putchar(char c);
void f_putstr(char const *s);

/* line functions */
char *read_line(void);
char **tokenize_line(char *arguments);
/* int readnparse(void); */

/* shell execution functions */
nt main(__attribute__((__unused__)) int ac, __attribute__((__unused__)) char **av);
void shell_prompt(void);
void find_path(void);
void loop_shell(char *line_cmd, char **tokens, int status);
int executor(char **arguments);
int forkd(char **str_args);

/* signal function */
void sigint_helper(__attribute__((__unused__)) int i);

/* PATH function */
int _process(char **args);

/* environ prototype */
extern char **environ;

/* global variables */
char pwd[1024];
char PATH[1024];

/* builtins */
int pwd_cmd(char **arguments);
int exit_cmd(char **arguments);

/* shell commands */
int f_clear(void);

#endif /* #ifndef SHELL_H */
