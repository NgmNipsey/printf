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

	if (format == NULL)
		return (-1);

	va_start(argList, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1), argCount++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1), argCount++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(argList, int);

				write(1, &c, 1), argCount++;
			}
			else if (*format == 's')
			{
				char *st = va_arg(argList, char *);
				int length = 0;

				while (st[length] != '\0')
					length++;
				write(1, st, length);
				argCount += length;
			}
		}
		format++;
	}
	va_end(argList);
	return (argCount);
}
