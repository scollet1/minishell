#include <stdio.h>
#include "../incl/minishell.h"

void		stack_trace(t_list *list)
{
	t_node *head;

	if (!list)
		return ;
	head = list->head;
	while (head != list->tail)
	{
		putendl(head->data);
		head = head->next;
	}
}

char	*err_invalid(const char *var)
{
	char *full_trace;

	full_trace = mini_cat(6, PROMPT, "input ", "\"", var, "\"", " invalid");
	return (full_trace);
}

char	*err_process(t_env *env, const char *func,
					 const char *var, const char *errmsg)
{
	char *full_trace;

	full_trace = mini_cat(10,
						  NON_FATAL_ERR, " in ", func, ": ",
						  var, " ", errmsg, " ", "(ERR_PRC)", "\n");
	if (push(&env->status.error.trace,
			 full_trace,
			 mini_strlen(full_trace)) == FAILURE)
	{
		env->status.error.errcode = FAILURE;
		mini_error(env, __func__, WHICH(env->status.error.trace),
				   "everything is broken -- blame the Samurai");
	}
	return (full_trace);
}

char 	*err_system(t_env *env, const char *func,
				  const char *var, const char *errmsg)
{
	char *full_trace;

	full_trace = mini_cat(10,
						  FATAL_ERR, " in ", func, ": ",
						  var, " ", errmsg, " (ERR_SYS)", "\n");
	env->status.running = 0;
	stack_trace(env->status.error.trace);
	return (full_trace);
}

int		mini_error(t_env *env, const char *func,
					  const char *var, const char *errmsg)
{
	if (!env)
		return (FAILURE);
	if (env->status.error.errcode == ERR_SYSTEM)
	{
		putendl(err_system(env, func, var, errmsg));
		return (FAILURE);
	}
	else if (env->status.error.errcode == ERR_PROCESS)
	{
		putendl(err_process(env, func, var, errmsg));
		return (FAILURE);
	}
	else if (env->status.error.errcode == ERR_INVALID)
	{
		putendl(err_invalid(var));
		return (SUCCESS);
	}
	return (SUCCESS);
}