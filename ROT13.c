#include "main.h"
#include <stdlib.h>

/**
 * p_R - prints a string in rot13
 * @ap: string to print
 *
 * Return: number of chars printed
 */

int p_R(va_list ap)
{
	char *s;
	unsigned int i, j;
	int count = 0;
	char orig[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char res[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(ahyy)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; orig[j]; j++)
		{
			if (orig[j] == s[i])
			{
				_putchar(res[j]);
				count++;
				break;
			}
		}
		if (!orig[j])
		{
			_putchar(s[i]);
			count++;
		}
	}
	return (count);
}
