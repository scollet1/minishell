#include "../incl/minishell.h"

char 	*mini_prompt(const char *prompt)
{
	ssize_t ret;
	char	*input;

	putendl(prompt);
	while (!(ret = mini_getline(STDIN_FILENO, &input)))
		;
	if (ret < 0)
		return (NULL);
	return (input);
}

void	mini_shell(t_env *env)
{
	char *input;

	while (env->status.running)
	{
		if ((input = mini_prompt(PROMPT)))
		{
			if (mini_dispatch(env, input) == FAILURE)
			{
				mini_error(env, __func__, "dispatch failed");
			}
		}
	}
	/*
	 * 			parse input();
	 * 			if parse == SUCCESS:
	 * 				if exec(env, input) == FAILURE:
	 * 					error(env, "in mini_shell(): ");
	 * 			else:
	 * 				error(env);
	 * 		else:
	 * 			error(env);
	 */
	(void*)input;
	(void*)env;
}

int		main(void)
{
	t_env *env;

	if (mini_init(&env))
		mini_shell(env);
	else
		error(env);
	/* TODO :
	 * initialize env
	 * if not env:
	 * 		error();
	 * else
	 * 		mini_shell(env);
	 * cleanup();
	 */
	return (0);
}