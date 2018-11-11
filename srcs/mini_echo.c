#include "../incl/minishell.h"

char	open_quotes(char *str)
{
	char 	q;
	int		open;

	q = '\0';
	open = 0;
	while (*str)
	{
		if ((*str == '\'' || *str == '"') && !open)
		{
			q = *str;
			open = 1;
		}
		else if (*str == q && open)
		{
			q = '\0';
			open = 0;
		}
		str++;
	}
	return (q);
}

void	quote_loop(const char *prompt,
					char *opts, char q,
					t_list **queue)
{
	char	*str;
	char	*closeq;

	str = replace(opts, q, '\0');
	while (1)
	{
		closeq = mini_prompt(prompt);
		if (!strncmp(closeq, &q, 1))
			break;
		else
			enqueue(queue, closeq, sizeof(closeq));
	}
}

int		mini_echo(t_env *env, char **opts)
{
	int		i;
	char 	q;
	t_list	*echo_queue;

	echo_queue = new_list();
	if (!env || !opts)
		return (FAILURE);
//	printf("%s\n", opts[0]);
	print(1, PROMPT);
	i = 0;
	if (*(++opts))
	{
		q = open_quotes(*opts);
		if (q)
			quote_loop("quote> ", *opts, q, &echo_queue);
		if (push(&echo_queue, *opts, sizeof(*opts)) == FAILURE)
			return (mini_error(env, __func__, WHICH(echo_queue), "enqueue"));
		dump_queue(&echo_queue, (void*)putstr);
	}
	print(1, "\n");
	return (SUCCESS);
}