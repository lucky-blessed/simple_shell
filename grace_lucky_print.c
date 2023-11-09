#include "shell.h"
/**
 * gl_print - Grace's and Lucky's customized print function
 * @word: Massage to be printed
 */
void gl_print(const char *word)
{
	write(STDOUT_FILENO, word, strlen(word));
}
