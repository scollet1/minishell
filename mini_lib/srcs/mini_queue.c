#include "../incl/mini_lib.h"

char	*cat_queue(t_list **queue)
{
	char	*str;

	if (!queue)
		return (NULL);
	str = NULL;
	while ((*queue)->head)
		mini_strcat(str, dequeue(queue)->data);
	return (str);
}

void	dump_queue(t_list **queue, void (*func)(void*))
{
	if (!queue || !func)
		return ;
	while ((*queue)->tail)
		func(dequeue(queue));
}

t_node	*dequeue(t_list **queue)
{
	return (pop(queue));
}

int 	enqueue(t_list **queue, void *data, size_t size)
{
	t_node	*node;

	if (!queue)
		return (FAILURE);
	node = new_node(data, size);
	if (!(*queue)->head)
	{
		(*queue)->head = node;
		(*queue)->tail = node;
		(*queue)->tail->prev = node;
		(*queue)->tail->next = node;
		node->prev = node;
		node->next = node;
		(*queue)->len++;
		return (SUCCESS);
	}
	(*queue)->head->prev = node;
	node->next = (*queue)->head;
	(*queue)->head = node;
	(*queue)->len++;
	return (SUCCESS);
}