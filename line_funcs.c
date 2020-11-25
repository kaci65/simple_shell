#include "shell.h"

/**
 * read_line - reads line from standard input
 * Return: buffer
 */
char *read_line(void)
{
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
}

/**
 * **tokenize_line - parses and breaks line into tokens
 * @arguments: arguments to be tokenized
 * Return: tokenized line of arguments
 */
char **tokenize_line(char *arguments)
{
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
