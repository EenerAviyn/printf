#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * func_selector - selects a function based on corresponding specifier.
 * @format: specifier
 *
 * Return: pointer to corresponding function.
 */
static int (*func_selector(const char *format))(va_list)
{
	unsigned int i = 0;
	id_f identf[] = {
		{"c", p_char},
		{"s", p_str},
		{"d", p_dec},
		{"i", p_int},
		{"b", p_binary},
		{"u", p_udec},
		{"o", p_oct},
		{"x", p_xhex},
		{"X", p_Xhex},
		{"S", p_S},
		{"p", p_p},
		{"R", p_R},
		{"r", p_r},
		{NULL, NULL}
	};

	while (identf[i].id != NULL)
	{
		if (*(identf[i].id) == *format)
		{
			break;
		}
		i++;
	}
	return (identf[i].f);
}

/**
 * _printf - produces output according to a format.
 * @format: character string.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end the output to strings on success or -1 on error.
 */

int _printf(const char *format, ...)
{
	int sum = 0;
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
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
								 params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
