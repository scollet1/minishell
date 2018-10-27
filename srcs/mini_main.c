#include "../incl/minishell.h"

char 	*mini_prompt(const char *prompt)
{
	ssize_t ret;
	char	*input;

	putstr(prompt);
	while (!(ret = mini_getline(STDIN_FILENO, &input)))
		;
	if (ret < 0)
		return (NULL);
	return (input);
}

int		mini_shell(t_env *env)
{
	char *input;

	while (env->status.running)
	{
		if ((input = mini_prompt(PROMPT)))
		{
			if (mini_dispatch(env, input) == FAILURE)
				return (mini_error(env, __func__, NULL, "dispatch failed"));
		}
		else
			return (mini_error(env, __func__, WHICH(input), "NULL"));
	}
	return (SUCCESS);
}

int		main(void)
{
	t_env *env;

	if (mini_init(&env))
	{
		putendl(WELCOME);
		if (mini_shell(env) == FAILURE)
			return (mini_error(env, __func__, NULL, "failed"));
	}
	else
		return (mini_error(env, __func__, WHICH(env), "uninitialied"));
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