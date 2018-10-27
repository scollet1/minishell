#include "../incl/minishell.h"

char		**mini_parser(const char *input)
{
	char **parsed;

	parsed = strsplit(input, ' ');
	return (parsed? parsed : NULL);
}