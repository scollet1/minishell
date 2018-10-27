#include "../incl/mini_lib.h"

char	*strnew(size_t size)
{
	char		*tmp;
	size_t		i;

	i = 0;
	if (!(tmp = (char*)memalloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
