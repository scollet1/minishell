#include "../incl/mini_lib.h"

void	*mini_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ret;
	unsigned char	*hold;

	ret = (unsigned char*)dst;
	hold = (unsigned char*)src;
	if (hold < ret)
	{
		ret = ret + len - 1;
		hold = hold + len - 1;
		while (len-- > 0)
			*ret-- = *hold--;
	}
	else if (ret < hold)
	{
		while (len > 0)
		{
			*ret++ = *hold++;
			len--;
		}
	}
	else
		return (hold);
	return (dst);
}
