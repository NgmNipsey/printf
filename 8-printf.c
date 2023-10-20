#include "main.h"

/**
 * print_hex - print unsigned hexa num.
 * @ap: pointer.
 * @params: parameter struct.
 * Return: pointer.
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long ln;
	int ac = 0;
	char *str;

	if (params->l_modifier)
		ln = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		ln = (unsigned short int)va_arg(ap, unsigned int);
	else
		ln = (unsigned int)va_arg(ap, unsigned int);
	str = convert(ln, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && ln)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (ac += print_number(str, params));
}

/**
 * print_HEX - print HEXA function.
 * @ap: pointer argument.
 * @params: parameter struct.
 * Return: Pointer.
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long ln;
	int ac = 0;
	char *str;

	if (params->l_modifier)
		ln = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		ln = (unsigned short int)va_arg(ap, unsigned int);
	else
		ln = (unsigned int)va_arg(ap, unsigned int);
	str = convert(ln, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && ln)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (ac += print_number(str, params));
}

/**
 * print_binary - print binary function.
 * @ap: pointer.
 * @params: struct parameters.
 *
 * Return: printed bytes.
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 2, CONVERT_UNSIGNED, params);
	int ac = 0;

	if (params->hashtag_flag && num)
		*--str = '0';
	params->unsign = 1;
	return (ac += print_number(str, params));
}

/**
 * print_octal - print octal function.
 * @ap: pointer.
 * @params: struct parameter.
 *
 * Return: printed bytes.
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long ln;
	int ac = 0;
	char *str;

	if (params->l_modifier)
		ln = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		ln = (unsigned short int)va_arg(ap, unsigned int);
	else
		ln = (unsigned int)va_arg(ap, unsigned int);
	str = convert(ln, 8, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && ln)
		*--str = '0';
	params->unsign = 1;
	return (ac += print_number(str, params));
}
