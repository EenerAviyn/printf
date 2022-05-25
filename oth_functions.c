#include "main.h"

/**
 * p_r - prints a string in reverse.
 * @ap: string to be printed.
 *
 * Return: no. of chars printed.
 */
int p_r(va_list ap)
{
	int i = 0, len = 0;
	char *s = va_arg(ap, char *);

	while (s[i])
		i++;
	while (i > 0)
	{
		_putchar(s[i - 1]);
		i--;
		len++;
	}
	return (len);
}
