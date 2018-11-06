#include "../incl/minishell.h"

char 	*mini_prompt(const char *prompt)
{
	ssize_t ret;
	char	*input;

	putstr(prompt);
	/*
	** In this line we're going to ingest the entire
	** string of bytes provided on stdin.
	*/
	while (!(ret = mini_getline(STDIN_FILENO, &input)))
		;
	if (ret < 0)
		return (NULL);
	return (input);
}

int		mini_shell(t_env *env)
{
	char *input;

	/*
	** In the case where a user does not want to leave the shell, and the shell has
	** not erred, it will run forever. On initialization we set the status of our
	** environment to running as an on/off switch. At any time during the program,
	** if we set this boolean to the off state, then we clean our memory and exit the
	** program
	*/
	while (env->status.running)
	{
		/*
		** every "cycle" of the shell we need to capture the user's input in a string
		** this determines the execution of subprocesses in the shell
		*/
		if ((input = mini_prompt(PROMPT)))
		{
			/*
			** to reduce code complexity we can employ a dispatch table. This is
			** an iterable mapping of strings to function pointers and helps us
			** standardize the way we handle program flow
			*/
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

	/*
	** Always initialize your environment and check for errors on the return
	*/
	if (mini_init(&env))
	{
		putendl(WELCOME);
		/*
		** I chose to propogate any errors back from the shell loop
		** for debugging and QA
		*/
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
