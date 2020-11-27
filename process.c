#include "shell.h"

/**
 * path - searches directories in PATH for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *path(char *command, char *fullpath, char *path)
{
  unsigned int cmd_len, pth_len, orig_pth_len;
  char *pth_cpy, *token;

  cmd_len = _strlen(command);
  orig_pth_len = _strlen(path);
  pth_cpy = malloc(sizeof(char) * orig_pth_len + 1);
  if (pth_cpy == NULL)
    {
      errors(3);
      return (NULL);
    }
  _strcpy(pth_cpy, path);
  /* copy PATH directory + command name and check if it exists */
  
  token = strtok(pth_cpy, ":"); /*tokenizes path to help with search*/
  if (token == NULL)
    token = strtok(NULL, ":");
  while (token != NULL)
    {
      pth_len = _strlen(token);
      fullpath = malloc(sizeof(char) * (pth_len + cmd_len) + 2);
      if (fullpath == NULL)
	{
	  errors(3);
	  return (NULL);
	}

      
      _strcpy(fullpath, token);
      fullpath[pth_len] = '/';
      _strcpy(fullpath + pth_len + 1, command);
      fullpath[pth_len + cmd_len + 1] = '\0';
      
      /*test whether file exists and grants read permision*/

if (access(fullpath, X_OK) != 0)
	{
	  free(fullpath);
	  fullpath = NULL;
	  token = strtok(NULL, ":");
	}
      else
	break;
    }
  free(pth_cpy);
  return (fullpath);
}
