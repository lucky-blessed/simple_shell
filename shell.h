#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>


void gl_prompt(void);
void gl_print(const char *word);
void gl_command_exe(const char *command);
void gl_command_reader(char *command, size_t lent);
void gl_command_args_exe(const char *command);

#endif /* SHELL_H */
