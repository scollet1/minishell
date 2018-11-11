#include "../incl/mini_lib.h"

char	*strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!(s))
		return (0);
	if (!(sub = (char*)memalloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
