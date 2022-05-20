#include "main.h"

/**
 * p_dec - handles the d specifier
 * @ap: arg pointer to decimal
 * Return: no of char printed
 */

int p_dec(va_list ap)
{
	int arr[10], i = 1, max, holder, total = 0, len = 0;

	holder = va_arg(ap, int);
	max = 1000000000;
	arr[0] = holder / max;

	while (i < 10)
	{
		max /= 10;
		arr[i] = (holder / max) % 10;
		i++;
	}
	if (holder < 0)
	{
		_putchar('-');
		len++;
		for (i = 0; i < 10; i++)
			arr[i] *= -1;
	}
	i = 0;
	while (i < 10)
	{
		total += arr[i];
		if (total != 0 || i == 9)
		{
			_putchar(arr[i] + '0');
			len++;
		}
		i++;
	}

	return (len);
}

/**
 * p_int - prints an int (handles the i specifier).
 * @ap: integer to be printed
 *
 * Return: number of chars printed
 */

int p_int(va_list ap)
{
	int arr[10], i = 1, max, holder, total = 0, len = 0;

	holder = va_arg(ap, int);
	max = 1000000000;
	arr[0] = holder / max;

	while (i < 10)
	{
		max /= 10;
		arr[i] = (holder / max) % 10;
		i++;
	}
	if (holder < 0)
	{
		_putchar('-');
		len++;
		for (i = 0; i < 10; i++)
			arr[i] *= -1;
	}
	i = 0;
	while (i < 10)
	{
		total += arr[i];
		if (total != 0 || i == 9)
		{
			_putchar(arr[i] + '0');
			len++;
		}
		i++;
	}

	return (len);
}

/**
 * _pow - calculates the value of b ^ e.
 * @b: base.
 * @e: power.
 *
 * Return: b^e.
 */
unsigned long _pow(unsigned int b, unsigned int e)
{
	unsigned int i;
	unsigned long pw = b;

	for (i = 1; i < e; i++)
		pw *= b;
	return (pw);
}
© 2022 GitHub, Inc.
Terms
Privacy