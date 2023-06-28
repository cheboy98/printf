#include "main.h"

/**
 * _strlen - compute the length of a string
 * @s: string
 *
 * Return: length
 */

int _strlen(char *s)
{
	int length;

	for (length = 0; s[length] != '\0'; length++)
		;

	return (length);
}
