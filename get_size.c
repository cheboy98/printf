#include "main.h"

/**
 * get_size - Calculates the size of the argument to be cast
 * @format: A formatted string for printing arguments
 * @i: List of arguments to be printed.
 *
 * Return: 0 (success).
 */
int get_size(const char *format, int *i)
{
	int current_index = *i + 1;

	if (format[current_index] == 'l')
	{
		*i = current_index;

		return (1);
	}
	else if (format[current_index] == 'h')
	{
		*i = current_index;

		return (-1);
	}

	*i = current_index - 1;

	return (0);
}
