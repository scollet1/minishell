#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

# include "../mini_lib/incl/mini_lib.h"

# ifndef WELCOME
# define WELCOME "~ミニシェルはあなたを歓迎する~"
# endif

# ifndef PROMPT
# define PROMPT "~-> "
# endif

typedef struct		s_error
{
	t_list			*trace;
	int 			errcode;
}					t_error;

/*
** status flags and our
** personal errno to
** update the state of
** our shell during runtime
*/
typedef struct		s_status
{
	uint8_t			running	:1;
	t_error			error;
}					t_status;

/*
** environment variables
** to use within our
** environment
*/
typedef struct		s_var
{
	char 			*val;
	char 			*var;
}					t_var;

/*
** environment to maintain
** shell state, variables,
** and other ancillary
** information needed during
** runtime
*/
typedef struct		s_env
{
	t_list			*vars;
	t_status		status;
}					t_env;

# ifndef DTAB_LEN
# define DTAB_LEN 1
# endif

typedef struct		s_dtab
{
	char			*name;
	int				(*func)(t_env*, char**);
}					t_dtab;

/*
** initialize our environment struct, passing
** the env by reference and mallocing the
** appropriate space. Other default struct
** values can be set here such as our linked
** list of environment variables
*/
int					mini_init(t_env **env);

/*
** @p env :
** @p errmsg :
** @p location :
** ---------------------------------------
** error handler function which sets our
** status values appropriately, such as in
** the case of an error, our status.error
** will be set to a custom errno and the
** minishell will act accordingly
*/
int		mini_error(t_env *env, const char *func,
					  const char *var, const char *errmsg);
/*
** @p env	: our environment struct containing necessary
** 				runtime information
** @p input : our const input, immutable as we are only reading
** 				it and acting on it. This parameter controls
** 				execution of functions directly after parsing
** 				so we must verify that it is correct before
** 				execution
** ------------------------------------------------------------
** the parser parses and verifies input -- lol
*/
int					mini_dispatch(t_env *env, const char *input);

char				*mini_prompt(const char *prompt);
char				**mini_parser(const char *input);
int					mini_exit(t_env *env, char **opts);
int					mini_echo(t_env *env, char **opts);
int					mini_setenv(t_env *env, char **opts);
int					mini_unsetenv(t_env *env, char **opts);
int 				mini_env(t_env *env, char**opts);
void				print(int done, ...);

#endif