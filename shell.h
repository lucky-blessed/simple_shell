#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char *gl_line_reader(void);
char **gl_line_tok(char *comm);
size_t gl_strlen(const char *X);
void gl_cmd_exec(char **args);

#endif /* SHELL_H */
