#include "../incl/minishell.h"

t_dtab g_disp[] = {
	{ "", NULL },
	{ NULL, NULL }
};

int 	mini_dispatch(t_env *env, const char *input)
{
	int		i;
	size_t	len;
	char	**parsed;

	if ((parsed = mini_parser(env, input)))
	{
		i = -1;
		len = mini_strlen(input);
		/*
		** iterate TAB and look for
		** the correct function to
		** execute our command(s)
		*/
		while (++i < DTAB_LEN)
			if (mini_strncmp(parsed[0], g_disp[i].name, len) == 0)
				return (g_disp[i].func(env, parsed));
		return (FAILURE);
	}
	return (FAILURE);
}