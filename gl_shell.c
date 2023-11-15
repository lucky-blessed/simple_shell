#include "shell.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *comm;
	char **args;

	while (1)
	{
		write(STDOUT_FILENO, "Grace_Lucky_shell$ ", 19);
		comm = gl_line_reader();
		if (!comm)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (*comm != '\0')
		{
			args = gl_line_tok(comm);
			if (args[0] != NULL)
			{
				gl_cmd_exec(args);
			}
			free(args);
		}
		free(comm);
	}
	return (0);
}
