#include "shell.h"
/**
 * gl_command_args_exe -Custom fn dat exe comm wt arg
 * @command: Command to be exe wt arg
 */
void gl_command_args_exe(const char *command)
{
	char *envp[] = {NULL};
	pid_t child_pid = fork();
	int arg_count = 0;

	if (child_pid == -1)
	{
		gl_print("Error in processing command.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[MAX_ARGS];
		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		execve(args[0], args, envp);
		gl_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
