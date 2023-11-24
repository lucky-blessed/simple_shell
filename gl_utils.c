#include "shell.h"
/**
 * gl_command_exe - Execute a command with argument
 * @command: The command to be executed
 */
void gl_command_exe(const char *command)
{
	int arg_count = 0;
	pid_t child_pid;
	char *args[MAX_ARGS];
	char command_copy[BUFFER_SIZE];
	char *token = strtok(command_copy, " ");

	child_pid = fork();
	if (child_pid == -1)
	{
		gl_print("Error in processing command.\n");
		_exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		strncpy(command_copy, command, sizeof(command_copy) - 1);
		command_copy[sizeof(command_copy) - 1] = '\0';
		while (token != NULL && arg_count < MAX_ARGS - 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		execve(args[0], args, environ);
		perror("Error executing command");
		_exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
}

/**
 * gl_path_handler - Exicute commands using PATH
 * @command: The command to be executed
 */
void gl_path_handler(const char *command)
{
	char *path = getenv("PATH");
	char *token;
	char full_path[MAX_PATH];

	if (path == NULL)
	{
		gl_print("Error: PATH environment variablr not set.\n");
		return;
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			gl_command_exe(full_path);
			break;
		}
		token = strtok(NULL, ":");
	}
}
