#include "../incl/minishell.h"

void		print(int args, ...)
{
	va_list ap;
	char	*str;

	str = NULL;
	va_start(ap, args);
	while (args)
	{
		str = va_arg(ap, char*);
		putstr(str);
		args--;
	}
	va_end(ap);
}