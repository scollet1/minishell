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

int		dump_queue(t_list **queue, void (*func)(void*), bool dump)
{
	t_node *tail;

	if (!queue || !func)
		return (FAILURE);
    tail = (*queue)->tail;
    while ((*queue)->tail)
	{
        func((*queue)->tail->data);
        if (dump)
		    free(dequeue(queue));
        else
            (*queue)->tail = (*queue)->tail->prev;
	}
    (*queue)->tail = tail;
	return (SUCCESS);
}

t_node	*dequeue(t_list **queue)
{
	return (pop(queue));
}

int 	enqueue(t_list **queue, void *data, size_t size)
{
	t_node	*node;

	if (!queue || !data)
		return (FAILURE);
	if (!(node = new_node(data, size)))
		return (FAILURE);
	if (!(*queue)->head)
	{
		(*queue)->head = node;
		(*queue)->tail = node;
		(*queue)->head->next = (*queue)->tail;
		(*queue)->head->prev = NULL;
		(*queue)->tail->prev = (*queue)->head;
		(*queue)->tail->next = NULL;
		(*queue)->len++;
		return (SUCCESS);
	}
	(*queue)->head->prev = node;
	node->next = (*queue)->head;
	(*queue)->head = node;
	(*queue)->len++;
	return (SUCCESS);
}