#include "main.h"

/**
 * print_char - function to print char.
 * @ap: pointer.
 * @params: struct parameter.
 *
 * Return: printed char.
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int padin = 0, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (padin++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - print int.
 * @ap: pointer.
 * @params: struct.
 * Return: printted int.
*/
int print_int(va_list ap, params_t *params)
{
	long ln;

	if (params->l_modifier)
		ln = va_arg(ap, int);
	else if (params->h_modifier)
		ln = (short int)va_arg(ap, int);
	else
		ln = (int)va_arg(ap, int);
	return (print_number(convert(ln, 10, 0, params), params));
}

/**
 * print_string - fucntion to prints string.
 * @ap: pointer.
 * @params: struct of paramters.
 *
 * Return: printed character string.
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int padin = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;

		j = padin = _strlen(str);
		if (params->precision < padin)
			j = padin = params->precision;
		if (params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				while (i < padin)
				{
					sum += _putchar(*str++);
					i++;
				}
			else
				sum += _puts(str);
		}
		while (j++ < params->width)
			sum += _putchar(pad_char);
		if (!params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				while (i < padin)
				{
					sum += _putchar(*str++);
					i++;
				}
			else
				sum += _puts(str);
		}
		return (sum);
}

/**
 * print_percent - print percent.
 * @ap: pointer.
 * @params: struct.
 *
 * Return: percentage sign.
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;

	return (_putchar('%'));
}

/**
 * print_S - print S capital.
 * @ap: pointer.
 * @params: struct.
 *
 * Return: sum.
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
			sum += _putchar(*str);
		str++;
	}
	return (sum);
}
