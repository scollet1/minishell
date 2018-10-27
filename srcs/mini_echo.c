#include "../incl/minishell.h"

int 	mini_echo(t_env *env, char **opts)
{
	int i;

	if (!env || !opts)
		return (FAILURE);
	printf("%s\n", opts[0]);
	print(1, PROMPT);
	i = 0;
	if (!*opts)
		print(1, "\n");
	else
		while (opts[++i])
			print(2, opts[i], " ");
	return (SUCCESS);
}