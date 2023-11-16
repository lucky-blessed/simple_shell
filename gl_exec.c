#include "shell.h"
/**
 * gl_cmd_exec - Grace Lucky command executor
 * @args: Argument vector
 * Return: NULL
 */
void gl_cmd_exec(char **args)
{
	pid_t child_process;
	int tracker;

	child_process = fork();
	if (child_process == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_process == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_process, &tracker, 0);
		if (WIFEXITED(tracker) && WEXITSTATUS(tracker) == 127)
		{
			write(STDOUT_FILENO, "Error: command not found\n", 25);
		}
	}
}
