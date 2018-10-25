#include "../incl/minishell.h"

void		mini_error(t_env *env,
					   const char *errmsg)
{
	if (!env)
		return ;
	if (env->status.error.errcode == FAILURE)
	{
		putstr("fatal:\n");
		env->status.running = 0;
		dump_stack(env->status.error.trace);
		return ;
	}
	if (push(&env->status.error.trace,
			 errmsg,
			 mini_strlen(errmsg)) < 0)
		env->status.error.errcode = FAILURE;
		mini_error(env, "in mini_error: push()");
}