#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>

typedef struct		s_var
{
	char 			*var;
	char 			*name;
	struct s_var 	*prev;
	struct s_var 	*next;
}					t_var;

typedef struct		s_env
{
	t_var			*head;
	t_var			*tail;
}					t_env;

#endif