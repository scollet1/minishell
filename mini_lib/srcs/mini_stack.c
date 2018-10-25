#include "../incl/mini_lib.h"

void		dump_stack()
{

}

int 		push(t_list **list, void *data, size_t size)
{
	t_node	*node;

	if (!list)
		return (FAILURE);
	node = new_node(data, size);
	if (!*list)
	{
		*list = new_list();
		(*list)->head = node;
		(*list)->tail = node;
		return (SUCCESS);
	}
	(*list)->head->prev = node;
	node->next = (*list)->head;
	(*list)->head = node;
	(*list)->len++;
	return (SUCCESS);
}