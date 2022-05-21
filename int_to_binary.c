#include "main.h"

/**
 * p_binary - handles custom conversion specifier: b
 * @ap: int to be printed
 * Return: number of chars printed
 */

int p_binary(va_list ap)
{
	unsigned int n, arr[33], len = 0;
	int i = 0;

	n = va_arg(ap, unsigned int);

	if (!n)
	{
		i++;
		arr[0] = 0;
	}
	while (n > 0)
	{
		arr[i] = n % 2;
		n /= 2;
		i++;
	}
	i--;

	while (i >= 0)
	{
		_putchar(arr[i] + '0');
		i--;
		len++;
	}
	return (len);
}

