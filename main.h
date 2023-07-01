#ifndef PRINTF_H
#define PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct format - structure to store the format of _printf
 * @format: store the current format
 * @f: function pointer to store the different format specifiers
 *
 */
typedef struct _format
{
	char format;
	int (*f)(va_list);
} _format;

int _printf(const char *format, ...);

int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);

int _putchar(char c);
int _strlen(char *s);

int _print_char(va_list);
int _print_str(va_list);
int _print_int(va_list);
int _print_unsigned_int(va_list);
int _print_bin(va_list);
int _print_oct(va_list);
int _print_hex_lower(va_list);
int _print_hex_upper(va_list);
int _print_pointer(va_list);
int _print_rev_str(va_list);
int _print_rot13(va_list);

#endif
