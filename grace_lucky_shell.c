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
		gl_command_exe(command);
	}
	return (0);
}
