#include "../incl/mini_lib.h"

char	*mini_strdup(const char *s1)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!(tmp = (char*)memalloc(sizeof(char) * (mini_strlen(s1) + 1))))
		return (0);
	while (s1[i] != 0)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*mini_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
