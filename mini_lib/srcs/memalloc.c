#include "../incl/mini_lib.h"

void	*memalloc(size_t size)
{
	char	*ret;

	if (!(ret = (void*)malloc(sizeof(char) * (size + 1))) || size >= 2147483647)
		return (0);
	mini_bzero(ret, size);
	return (ret);
}
