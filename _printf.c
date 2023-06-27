#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Custom printf function
 * @format: format string.
 * Return: total chars.
 */
int _printf(const char *format, ...)
{
	va_list list;
	char buffer[BUFF_SIZE];
	int buff_ind = 0;
	int total_chars = 0;
	int j;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (int j = 0; format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];

			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				total_chars += buff_ind;

			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			++j;
			handle_print(format, &j, list, buffer, &buff_ind);
			total_chars += buff_ind;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (total_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of characters
 * @buff_ind: The index of the next char represents its length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

