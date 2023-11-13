#include "shell.h"

/**
 * gl_command_exe - Customized Function that executes command
 * @command: Command to be executed
 *
 * Return: void
 */
void gl_command_exe(const char *command)
{
	char *exec_env_path[] = {NULL};
	int arg_count = 0;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		gl_print("Error in processing command.\n");
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
		/* execvp(args[0], args); */
		execve(args[0], args, exec_env_path);
		gl_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
