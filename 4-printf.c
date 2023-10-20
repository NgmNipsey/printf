#include "main.h"

/**
 * get_precision - precision functions.
 * @p: character string.
 * @params: parameters struct.
 * @ap: pointer.
 *
 * Return: Pointer.
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int ac = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		ac = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
		ac = ac + 10 + (*p++ - '0');
	}
	params->precision = ac;
	return (p);
}
