 #include "shell.h"
/**
 * main - The entry point to the main function
 * Return: 0 (Success).
 */
int main(void)
{
	char command[BUFFER_SIZE];

	while (true)
	{
		gl_prompt();
		gl_command_reader(command, sizeof(command));
		gl_command_exe(command);
		if (strchr(command, ' ') != NULL)
		{
			gl_command_exe(command);
		}
		else
		{
			gl_path_handler(command);
		}
		gl_path_handler(command);
	}
	return (0);
}
