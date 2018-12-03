#include "../incl/minishell.h"

int 	mini_env(t_env *env, char **opts)
{
    (void)opts;
	return (dump_stack(env->vars, (void*)putendl, false));
}

int 	mini_unsetenv(t_env *env, char **opts)
{
	(void)env;
	(void)opts;
	return (SUCCESS);
}

int 	mini_setenv(t_env *env, char **opts)
{
	(void)env;
	(void)opts;
	return (SUCCESS);
}