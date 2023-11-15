#include "shell.h"
/**
 * gl_strlen - costimised function to count lent of string
 * @X: String to be counted.
 * Return: Lent
 */
size_t gl_strlen(const char *X)
{
	size_t length = 0;

	while (X[length] != '\0')
	{
		length++;
	}
	return (length);
}
