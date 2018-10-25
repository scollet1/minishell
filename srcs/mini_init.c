#include "../incl/minishell.h"

int		mini_init(t_env **env)
{
	if (!(*env = (t_env*)memalloc(sizeof(t_env))))
		return (-1);

	(*env)->status.running = 1;
	return (1);
}