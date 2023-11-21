#include "shell.h"

/**
 * gl_command_exe - Customized Function that executes command
 * @command: Command to be executed
 *
 * Return: void
 */
void gl_command_exe(const char *command)
{
	char *envp[] = {NULL};
	int arg_count = 0;
	pid_t child_pid = fork();
	int i;
	char *args[MAX_ARGS];

	if (child_pid == -1)
	{
		gl_print("Error in processing command.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[MAX_ARGS];
		char *token = strtok((char *)command, " ");

		while (token != NULL && arg_count < MAX_ARGS - 1)
		{
			args[arg_count++] = strdup(token);
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		/* execvp(args[0], args); */
		execve(args[0], args, envp);
		gl_print("No such file or directory found.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		for (i = 0; i < arg_count; i++)
		{
			args[i] = strdup(args[i]);
			free(args[i]);
		}
	}
}
