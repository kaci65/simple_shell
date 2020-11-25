#include "shell.h"

/**
 * f_clear - clears input from screen
 * Return: 0 if successful
 */
int f_clear(void)
{
	write(1, "\33[H\33[2J", 7);
	return (0);
}
