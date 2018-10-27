#include "../incl/mini_lib.h"

void	mini_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
