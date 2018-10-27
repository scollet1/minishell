#include "../incl/minishell.h"

void		print(int done, ...)
{
	va_list ap;
	char	*str;

	str = NULL;
	va_start(ap, done);
	while (!done)
	{
		str = va_arg(ap, char*);
		putstr(str);
		done--;
	}
	va_end(ap);
}