#include "../incl/minishell.h"

t_list	*open_quotes(char *str)
{
	char 	q;
	t_list	*tokens;

	tokens = NULL;
	q = lex(&tokens, str, 2, '\"', '\'');
	if (!q)
		return (NULL);
	else if (q == '\'' || q == '\"')
		return (quote_loop("quote> ", q, &tokens));
	return (tokens);
}

t_list	*quote_loop(const char *prompt, char q, t_list **queue)
{
	char	*closeq;

	enqueue(queue, &(char*){"\n"}, 1);
	while (1)
	{
		closeq = mini_prompt(prompt);
		if (!strncmp(closeq, &q, 1))
			break;
		else
		{
			enqueue(queue, &closeq, mini_strlen(closeq));
			enqueue(queue, &(char*){"\n"}, 1);
		}
	}
	return (*queue);
}

int		mini_echo(t_env *env, char **opts)
{
	char 	*str;
	t_list	*echo_queue;

	echo_queue = new_list();
	if (!env || !opts)
		return (FAILURE);
	if (*(++opts))
	{
		if (!(str = mini_join(opts, " ")))
			mini_error(env, __func__, WHICH(str), "null string");
		if (!(echo_queue = open_quotes(str)))
		{
			env->status.error.errcode = ERR_PROCESS;
			mini_error(env, __func__, WHICH(echo_queue), "lexing");
		}
		dump_queue(&echo_queue, (void*)putstr);
	}
	print(1, "\n");
	return (SUCCESS);
}