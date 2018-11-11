#include "../incl/minishell.h"

char	open_quotes(char *str)
{
	char 	q;
	int		open;
	t_list	*queue;

	q = '\0';
	open = 0;
	while (*str)
	{
		if ((*str == '\'' || *str == '\"') && !open)
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

int		mini_echo(t_env *env, char **opts)
{
	int		i;
	char 	*q;
	char	*closeq;
	t_list	*echo_queue;

	if (!env || !opts)
		return (FAILURE);
	printf("%s\n", opts[0]);
	print(1, PROMPT);
	i = 0;
	if (!*opts)
	{
		print(1, "\n");
	}
	else
	{
		q = open_quotes(opts[1]);
		opts[1] = replace(opts[1], q, '\0');
		{
			while (!closed)
			{
				closeq = prompt("quote> ");
				if (!strncmp(closeq, q, 1))
					closed = 1;
				else
					enqueue(&echo_queue, closeq, sizeof(closeq));
			}
		}
		dump_queue(echo_queue, putstr);
	}
	return (SUCCESS);
}