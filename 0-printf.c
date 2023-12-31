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
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')
		{
			argCount += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			argCount += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			argCount += get_print_func(p, ap, &params);
	}
	_putchar(BUFF_FLUSH);
	va_end(ap);
	return (argCount);
}
