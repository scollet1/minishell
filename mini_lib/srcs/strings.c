#include "../incl/mini_lib.h"

char	*catfun(char *str, char chr)
{
	if (chr)
		return (NULL);
	return (str);
}

char	*replace(char *strn, char find, char rplc)
{
	int		i;
	int 	len;

	i = -1;
	len = mini_strlen(strn);
	while (*strn)
	{
		if (*strn == find)
			*strn = rplc;
		strn++;
	}
	if (!rplc)
		return (nullcat(strn, len));
	return (strn);
}