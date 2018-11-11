#include "../incl/mini_lib.h"

char	*cat_queue(t_list **queue)
{
	char	*str;

	if (!queue)
		return ;
	while ((*queue)->head)
		mini_strcat(str, dequeue(queue)->data);
	return (str);
}

void	dump_queue(t_list **queue, void (*func)(void*))
{
	t_node *tail;

	if (!queue || !func)
		return ;
	tail = queue->tail;
	while (tail != queue->head)
	{
		func(tail->data);
		dequeue(&queue);
	}
}

t_node	*dequeue(t_list **queue)
{
	t_node	*ret;

	if (!queue)
		return (NULL);
	ret = (*queue)->tail;
	(*queue)->tail = (*queue)->tail->prev;
	(*queue)->tail->next = NULL;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

int 	enqueue(t_queue **queue, void *data, size_t size)
{
	return (push(queue, data, size));
}