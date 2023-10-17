#include "main.h"

/**
 * _printf - printf to handles out like c, %, s.
 * @format: Const string charater.
 *
 * Return: Count.
 */
int _printf(const char *format, ...)
{
	int argCount = 0;
	va_list argList;

	va_start(argList, format);
	if (format == NULL)
		return (1);
	while (*format)
	{
		write(1, format, 1);
		argCount++;

		format++;
	}
	return (argCount);
}
