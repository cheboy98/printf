#include "main.h"

int print_str(char *s);
/**
 * _printf - write to stdout
 * @format: string to print
 *
 * Return: an int
 */
int _printf(const char *format, ...)
{
	va_list list;
	char *s, c, buf[64];
	int num, ret_val = 0;

	va_start(list, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ret_val += write(1, "%", 1);
			else if (*format == '\0')
				return (-1);
			else if (*format == 'c')
			{
				c = va_arg(list, int);
				ret_val += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				s = va_arg(list, char *);
				if (s == NULL)
					s = "(null)";
				ret_val += write(1, s, _strlen(s));
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(list, int);
				snprintf(buf, sizeof(buf), "%d", num);
				ret_val += write(1, buf, _strlen(buf));
			}
			else
			{
				ret_val += write(1, "%", 1);
				ret_val += write(1, format, 1);
			}
		}
		else
			ret_val += write(1, format, 1);
		format++;
	}
	va_end(list);
	return (ret_val);
}
/**
 * print_str - print a string to the stdout
 * @s: string to print
 *
 * Return: 0
 */
