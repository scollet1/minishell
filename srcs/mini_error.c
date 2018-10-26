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

void		mini_error(t_env *env, const char *func, const char *errmsg)
{
	char	*full_trace;

	if (!env)
		return ;
	full_trace = mini_cat(4, "in ", func, ": ", errmsg);
	if (env->status.error.errcode == FAILURE)
	{
		putstr("fatal:\n");
		env->status.running = 0;
		stack_trace(env->status.error.trace);
		return ;
	}
	else
	{

		if (push(&env->status.error.trace,
				 full_trace,
				 mini_strlen(full_trace)) == FAILURE)
			env->status.error.errcode = FAILURE;
		mini_error(env, __func__, "everything is broken -- \
									blame the Samurai");
	}
}