#include "../incl/mini_lib.h"

t_node	*new_node(void *data, size_t size)
{
	t_node *node;

	if (!data)
		return (NULL);
	if (!(node = (t_node*)memalloc(sizeof(t_node))))
		return (NULL);
	mini_memcpy(&node->data, data, size);
	node->size = size;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
