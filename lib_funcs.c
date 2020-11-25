#include "shell.h"

/**
 * f_strcmp - compares two strings
 * @s1: compare with s2
 * @s2: compare with s1
 * Return: integer
 */
int f_strcmp(char *s1, char *s2)
{
  int i;
  int result;

  for (i = 0; s1[i] != '\0'; i++)
    {
      if (s1[i] > s2[i])
	{
	  result = s1[i] - s2[i];
	  return (result);
	}
      else if (s1[i] < s2[i])
	{
	  result = s1[i] - s2[i];
	  return (result);
	}
    }
  return (0);
}

/**
 * f_strcopy - copies the string from pointer src to pointer dest
 * @dest: have src contents
 * @src: copy contents to dest
 * Return: Pointer to dest
 */
char *f_strcopy(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  *(dest + i) = '\0';
  return (dest);
}

/**
 * f_strcat - concatenates two strings
 * @dest: string dest
 * @src: string to be appended
 * Return: pointer to destination string dest
 */
char *f_strcat(char *dest, char *src)
{
  int i;
  int j;

  for (i = 0; dest[i] != '\0'; i++)
    {
    }

  j = 0;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i++;
      j++;
    }

  dest[i] = '\0';
  return (dest);

}

/**
 * f_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 *
 * Desc: First parameter in the write function is the file
 * descriptor of where to
 * write the output, we use one for standard output
 * Second parameter is a null terminated character string of the
 * content to write. We give the address to our char c parameter
 * Last parameter is the number of bytes to write. We have one character
 * we want to write that is 1 byte so we put a 1 as the parameter
 */
int f_putchar(char c)
{
  return (write(1, &c, 1));
}

/**
 * f_putstr - displays the string s to the standard output
 * @s: string to be displayed
 * Return: Nothing
 */
void f_putstr(char const *s)
{
  size_ti;

  i = 0;
  while (s[i])
    {
      f_putchar(s[i]);
      i++;
    }
}
