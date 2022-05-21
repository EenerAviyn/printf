#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

/**
 * struct id_func - Struct id_func
 *
 * @id: identifier.
 * @f: corresponding function.
 */
typedef struct id_func
{
	char *id;
	int (*f)(va_list);
} id_f;

int _putchar(char c);
int _printf(const char *format, ...);
int p_char(va_list ap);
int p_str(va_list ap);
int p_int(va_list ap);
int p_dec(va_list ap);
int p_binary(va_list ap);
int p_udec(va_list ap);
int p_Xhex(va_list ap);
int p_xhex(va_list ap);
int p_oct(va_list ap);
int p_udec(va_list ap);
int p_S(va_list ap);
int p_p(va_list ap);
unsigned long _pow(unsigned int b, unsigned int e);
int p_r(va_list ap);
int p_R(va_list ap);
#endif
