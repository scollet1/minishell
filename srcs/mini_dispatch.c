#include "../incl/minishell.h"

t_dtab g_disp[] = {
	{ "exit", mini_exit },
	{ "quit", mini_exit },
	{ "echo", mini_echo },
	{ "setenv", mini_setenv },
	{ "unsetenv", mini_unsetenv },
	{ "env", mini_env },
	{ NULL, NULL }
};

int 	mini_dispatch(t_env *env, const char *input)
{
	int		i;
	size_t	len;
	char	**parsed;

	if ((parsed = mini_parser(input)))
	{
		i = -1;
		len = mini_strlen(parsed[0]);
		/*
		** iterate TAB and look for
		** the correct function to
		** execute our command(s)
		*/
		while (g_disp[++i].name)
			if (mini_strncmp(parsed[0], g_disp[i].name, len) == SUCCESS)
				return (g_disp[i].func(env, parsed));
		env->status.error.errcode = ERR_INVALID;
		return (mini_error(env, __func__, parsed[0], ""));
	}
	return (FAILURE);
}