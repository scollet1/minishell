#include "../incl/mini_lib.h"

int 	enqueue(t_list **list, void *data, size_t size)
{
	return (push(list, data, size));
}

