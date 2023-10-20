#include "main.h"

/**
 * get_specifier - print various assigned specifiers.
 * @s: string character.
 *
 * Return: NULL.
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"P", print_address},
		{"S", print_S},
		{"r", print_r},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int j = 0;

	while (specifiers[j].specifier)
	{
		if (*s == specifiers[j]. specifier[0])
		{
			return (specifiers[j].f);
		}
		j++;
	}
	return (NULL);
}

/**
 * get_print_func - print function formats stdout.
 * @s: hold string.
 * @ap: pointer to the argument.
 * @params: struct.
 *
 * Return: 0 or function pointer.
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - specify the flag values.
 * @s: string character.
 * @params: struct of parameters.
 *
 * Return: integer of j.
 */
int get_flag(char *s, params_t *params)
{
	int j = 0;

	switch (*s)
	{
		case '+':
			j = params->plus_flag = 1;
			break;
		case '0':
			j = params->zero_flag = 1;
			break;
		case '#':
			j = params->hashtag_flag = 1;
			break;
		case ' ':
			j = params->space_flag = 1;
			break;
		case '-':
			j = params->minus_flag = 1;
	}
	return (j);
}

/**
 * get_modifier - modifiers function.
 * @s: character string.
 * @params: parameter struct.
 *
 * Return: J
 */
int get_modifier(char *s, params_t *params)
{
	int j = 0;

	switch (*s)
	{
		case 'l':
			j = params->l_modifier = 1;
			break;
		case 'h':
			j = parmas->h_modifier = 1;
			break;
	}
	return (j);
}

/**
 * get_width - get width function.
 * @s: chsracter string.
 * @params: struct of paramenter.
 * @ap: pointer.
 *
 * Return: pointer.
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int ac = 0;

	if (*s == '*')
	{
		ac = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			ac = ac + 10 + (*s++ - '0');
	}
	params->width = ac;
	return (s);
}
