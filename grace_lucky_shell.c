 #include "shell.h"
/**
 * main - The entry point to the main function
 * Return: 0 (Success).
 */
int main(void)
{
	char command[120];

	while (true)
	{
		gl_prompt();
		gl_command_reader(command, sizeof(command));
		if (strchr(command, ' ') != NULL)
		{
			gl_command_args_exe(command);
		}
		else
		{
			gl_command_exe(command);
		}
	}
	return (0);
}
