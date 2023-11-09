#include "shell.h"
/**
 * gl_command_reader - Reads user input command
 * @command: The command to be interpreted
 * @lent: length of characters of the command
 * Return: void
 */
void gl_command_reader(char *command, size_t lent)
{
	if (fgets(command, lent, stdin) == NULL)
	{
		if (feof(stdin))
		{
			gl_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			gl_print("The is an error reading the command");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
