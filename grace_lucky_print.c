#include "shell.h"
/**
 * gl_print - Grace's and Lucky's customized print function for this project.
 * @word: Massage to be printed to the standard output.
 */
void gl_print(const char *word)
{
	write(STDOUT_FILENO, word, strlen(word));
}
