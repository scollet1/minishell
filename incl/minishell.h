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
# define PROMPT "~->"
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

/*
** initialize our environment struct, passing
** the env by reference and mallocing the
** appropriate space. Other default struct
** values can be set here such as our linked
** list of environment variables
*/
int					mini_init(t_env **env);

/*
** error handler function which sets our
** status values appropriately, such as in
** the case of an error, our status.error
** will be set to a custom errno and the
** minishell will act accordingly
*/
void		mini_error(t_env *env, const char *errmsg);

#endif