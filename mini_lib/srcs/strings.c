#include "../incl/mini_lib.h"

char	*catfun(char *str, char chr)
{
	if (chr)
		return (NULL);
	return (str);
}

int 	is_allchar(char *str, char c, size_t len)
{
	size_t i;

	i = 0;
	if (!str || !len)
		return (-1);
	while (i < len)
		if (str[i++] != c)
			return (0);
	return (1);
}

char	*replace(char *strn, char find, char rplc)
{
	int 	len;

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