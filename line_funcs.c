#include "shell.h"

/**
 * read_line - reads line from standard input
 * Return: buffer
 */
char *read_line(void)
{
<<<<<<< HEAD
    /* changing end of line to null terminating */
    char *buf = NULL; /* holds line contents */
    size_t buf_size = 0;
    ssize_t line_size;

  /* Get the first line of the file. */
    line_size = getline(&buf, &buf_size, stdin);

    if (line_size == EOF)
    {
        /* Free the allocated line buffer */
        free(buf);
        return (NULL);
    }

  return (buf);
=======
char *buf = NULL; /* holds line contents */
size_t buf_size = 0;
ssize_t line_size;

/* Get the first line of the file. */
line_size = getline(&buf, &buf_size, stdin);

if (line_size == EOF)
{
free(buf);
exit(EXIT_SUCCESS);
}

fflush(stdin);

/* Free the allocated line buffer */
free(buf);
/* changing end of line to null terminating */
buf = NULL;

return (buf);
>>>>>>> 2edff05aa665739e83c8ded54c52f69eb42eec66
}

/**
 * **tokenize_line - parses and breaks line into tokens
 * @arguments: arguments to be tokenized
 * Return: tokenized line of arguments
 */
char **tokenize_line(char *arguments)
{
<<<<<<< HEAD
    int len = 0;
    int index = 0;
    char **cmd_line_toks;
    char *cmd_line;

    while (arguments[len] != '\0')
    {
        len++;
    }

    cmd_line_toks = malloc(len * sizeof(char *);

    /**
     * delimiters - characters used to split the string 
     * strtok returns a pointer to the character of next token
     * So first time it's called, it points to the first word
     * strtok modifies the original string. It puts NULL characters ('\0') 
     * at the delimiter position after every call to strtok to track tokens
     * strtok also internally remembers the next token's starting position
     */

    cmd_line = strtok(arguments, DELIMITERS);
    while (cmd_line != NULL)
    {
        cmd_line_toks[index] = cmd_line;
        index++;
        /** 
         * In the next call to strtok, first parameter needs to be NULL
         * so that strtok starts splitting the string from the next token's
         * starting position it remembers
         */
        cmd_line = strtok(NULL, DELIMITERS);
    }

    if (cmd_line_toks == NULL)
    {
        free_doublegrid(cmd_line_toks);
        exit(0);
    }
    cmd_line_toks[index] = NULL;

    return (cmd_line_toks);
}
=======
size_t num_toks;
int index = 0;
char **cmd_line_toks = malloc(sizeof(char *) * num_toks);
char *cmd_line;

cmd_line = strtok(arguments, " ");
if (cmd_line != NULL)
{
cmd_line_toks[index] = cmd_line;
index++;
cmd_line = strtok(NULL, " ");
}
cmd_line_toks[index] = NULL;
free(cmd_line_toks);

return (cmd_line_toks);
}
>>>>>>> 2edff05aa665739e83c8ded54c52f69eb42eec66
