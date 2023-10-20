#include "main.h"

/**
 * _puts - outputs string.
 * @str: pointer.
 *
 * Return: pointer.
 */
int _puts(char *str)
{
	char *st = str;

	while (*str)
		_putchar(*str++);
	return (str - st);
}

/**
 * _putchar - print an int.
 * @c: Hold int value.
 *
 * Return: integer.
 */
int _putchar(int c)
{
	static int j;
	static char buff[BUFF_SIZE];

	if (c == BUFF_FLUSH || j >= BUFF_SIZE)
	{
		write(1, buff, j);
		j = 0;
	}
	if (c != BUFF_FLUSH)
		buff[j++] = c;
	return (1);
}
