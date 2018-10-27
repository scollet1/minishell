#include "../incl/minishell.h"

int		mini_exit(t_env *env, char **opts)
{
	if (!env)
		return (FAILURE);
	(void)opts;
	env->status.running = 0;
	return (SUCCESS);
}