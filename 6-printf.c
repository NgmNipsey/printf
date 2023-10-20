#include "main.h"

/**
 * convert - function conversion for hex & HEX.
 * @num: number.
 * @base: base.
 * @flags: flags argumennt.
 * @params: parameters struct.
 *
 * Return: string.
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = num;
		sign = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - print unsigned int.
 * @ap: pointer.
 * @params: struct parameters.
 *
 * Return: printed bytes.
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long lg;

	if (params->l_modifier)
		lg = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lg = (unsigned short int)va_arg(ap, unsigned int);
	else
		lg = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(lg, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - print adress function.
 * @ap: pointer argument.
 * @params: struct parameter.
 *
 * Return: printted address.
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));
	str = convert(n, 10, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
