#include "../incl/minishell.h"

char		**mini_parser(t_env *env, const char *input)
{
	char **parsed;

	parsed = strsplit(input, ' ');
	return (parsed? parsed : NULL);
}