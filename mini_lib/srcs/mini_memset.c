#include "../incl/mini_lib.h"

void	*mini_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	char			*pb;

	a = (unsigned char)c;
	i = 0;
	pb = (char*)b;
	while (i < len)
		pb[i++] = a;
	b = (void*)pb;
	return (b);
}
