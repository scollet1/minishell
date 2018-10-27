#include "../incl/mini_lib.h"

void	*mini_memcpy(void *dst, const void *src, size_t n)
{
	return (mini_memmove(dst, src, n));
}
