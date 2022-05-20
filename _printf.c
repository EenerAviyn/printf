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
	unsigned int i = 0, j = 0;		/* i -loop and j -counter */
	va_list ap;				/* req in variadic functions */
	int (*func)(va_list);			/* pointer to function */

	/* check for nullity */
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			i++;
			j++;
		}
		if (!format[i])
			return (j);
		func = func_selector(&format[i + 1]);
		if (func != NULL)
		{
			j += func(ap);		/* count what is printed */
			i += 2;			/* escape '%' and identifier */
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		j++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);

	return (j);
}
© 2022 GitHub, Inc.
Terms
