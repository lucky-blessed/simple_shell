#include "shell.h"
/**
 * gl_line_reader - Get input from stdin
 * Return: User input
 */
char *gl_line_reader(void)
{
	char *comm = NULL;
	size_t holder_size = 0;
	ssize_t R;

	R = getline(&comm, &holder_size, stdin);
	if (R == -1)
	{
		free(comm);
		return (NULL);
	}
	if (comm[R - 1] == '\n')
	{
		comm[R - 1] = '\n';
	}
	return (comm);
}
