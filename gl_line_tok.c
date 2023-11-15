#include "shell.h"
/**
 * gl_line_tok - function to split line into arguments and tokenize it.
 * @comm: Stream of argurments
 * Return: Token
 */
char **gl_line_tok(char *comm)
{
	size_t holder_size = 64;
	size_t state = 0;
	char *TOK;
	char **toks;

	toks = malloc(sizeof(char *));
	if (!toks)
	{
		perror("Error in mem allocation");
		exit(EXIT_FAILURE);
	}
	TOK = strtok(comm, " ");
	while (TOK != NULL)
	{
		toks[state] = TOK;
		state++;
		if (state >= holder_size)
		{
			holder_size += 64;
			toks = realloc(toks, holder_size * sizeof(char *));
			if (!toks)
			{
				perror("Error in mem reallocation");
				exit(EXIT_FAILURE);
			}
		}
		TOK = strtok(NULL, " ");
	}
	if (state > 0)
	{
		size_t LEN_TOK = gl_strlen(toks[state - 1]);

		if (LEN_TOK > 0 && toks[state - 1][LEN_TOK - 1] == '\n')
		{
			toks[state - 1][LEN_TOK - 1] = '\0';
		}
	}
	toks[state] = NULL;
	return (toks);
}
