#include "../incl/minishell.h"

t_list	*open_quotes(char *str)
{
	char 	q;
	t_list	*tokens;

	tokens = NULL;
	q = lex(&tokens, str, 2, '\"', '\'');
	if (!q)
		return (NULL);
	else if (q != '!' && q != '.')
		return (quote_loop("quote> ", q, &tokens));
	return (tokens);
}

t_list	*quote_loop(const char *prompt, char q, t_list **queue)
{
	char	*closeq;

	while (1)
	{
		closeq = mini_prompt(prompt);
		if (!strncmp(closeq, &q, 1))
			break;
		else
			enqueue(queue, closeq, sizeof(closeq));
	}
	return (*queue);
}

int		mini_echo(t_env *env, char **opts)
{
	t_list	*echo_queue;

	echo_queue = new_list();
	if (!env || !opts)
		return (FAILURE);
//	printf("%s\n", opts[0]);
//	print(1, PROMPT);
	if (*(++opts))
	{
		if (!(echo_queue = open_quotes(*opts)))
			mini_error(env, __func__, WHICH(echo_queue), "lexing");
		dump_queue(&echo_queue, (void*)putstr);
	}
	print(1, "\n");
	return (SUCCESS);
}