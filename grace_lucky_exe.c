#include "shell.h"

/**
 * gl_command_exe - Function that executes command
 * @command: Command to be executed
 *
 * Return: void
 */
void gl_command_exe(const char *command)
{
	int arg_count = 0;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		gl_print("Error if processing.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[128];
		char *token = strtok((char *)command, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		execvp(args[0], args);
		gl_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
