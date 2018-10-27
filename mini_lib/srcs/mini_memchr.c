#include "../incl/mini_lib.h"

void	*mini_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*p;

	i = 0;
	d = (unsigned char)c;
	p = (unsigned char*)s;
	while (i < n)
	{
		if (p[i] == d)
			return (&p[i]);
		i++;
	}
	return (0);
}
