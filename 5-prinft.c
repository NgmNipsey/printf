#include "main.h"

/**
 * print_from_to - print address ranges.
 * @start: hold starting pointer.
 * @stop: hold ending pointer.
 * @except: with exception.
 *
 * Return: argCount.
 */
int print_from_to(char *start, char *stop, char *except)
{
	int argCount = 0;

	while (start <= stop)
	{
		if (start != except)
			argCount += _putchar(*start);
		start++;
	}
	return (argCount);
}

/**
 * print_rev - print in reverse format.
 * @ap: pointer.
 * @params: struct of parameters.
 *
 * Return: argCount bytes.
 */
int print_rev(va_list ap, params_t *params)
{
	int i, argCount = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (i = 0; *str; str++)
			i++;
		str--;
		for (; i > 0; i--, str--)
			argCount += _putchar(*str);
	}
	return (argCount);
}

/**
 * print_rot13 - print more bytes.
 * @ap: pointer argument.
 * @params: parameter struct.
 *
 * Return: Count of bytes.
 */
int print_rot13(va_list ap, params_t *params)
{
	int i, index, count = 0;
	char ar[] = "NOPQRSTUVWXYZABCDEFGHIJKLM   nopqrstuvwxyzabcdefghijklm";
	char *arr = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (arr[i])
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))
		{
			index = arr[i] - 65;
			count += _putchar(ar[index]);
		}
		else
			_putchar(arr[i]);
		i++;
	}
	return (count);
}
