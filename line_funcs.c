#include "shell.h"

/**
 * read_line - reads line from standard input
 * Return: buffer
 */
char *read_line(void)
{
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
}

/**
 * **tokenize_line - parses and breaks line into tokens
 * @arguments: arguments to be tokenized
 * Return: tokenized line of arguments
 */

char **tokenize_line(char *arguments)
{
	int len = 0;
	int index = 0;
	char **cmd_line_toks;
	char *cmd_line;

	while (arguments[len] != '\0')
	{
		len++;
	}

	cmd_line_toks = malloc(len * sizeof(char *));

			cmd_line = strtok(arguments, DELIMITERS);
			while (cmd_line != NULL)
			{
			cmd_line_toks[index] = cmd_line;
			index++;
			cmd_line = strtok(NULL, DELIMITERS);
			}

			if (cmd_line_toks == NULL)
			{
			free_doublegrid(cmd_line_toks);
			exit(0);
			}
			/* changing end of line to null terminating */
			cmd_line_toks[index] = NULL;

			return (cmd_line_toks);
			}

/**
 * delimiters - characters used to split the string
 * strtok returns a pointer to the character of next token
 * So first time it's called, it points to the first word
 * strtok modifies the original string. It puts NULL characters ('\0')
 * at the delimiter position after every call to strtok to track tokens
 * strtok also internally remembers the next token's starting position
 *
 * In the next call to strtok, first parameter needs to be NULL
 * so that strtok starts splitting the string from the next token's
 * starting position it remembers
 */
