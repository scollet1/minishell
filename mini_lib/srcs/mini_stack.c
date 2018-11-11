#include "../incl/mini_lib.h"

void		dump_stack(t_list *stack, void (*func)(void*))
{
	t_node *head;

	if (!stack || !func)
		return ;
	head = stack->head;
	while (head != stack->tail)
	{
		func(head->data);
		pop(&stack);
	}
}

#include <stdio.h>
t_node		*pop(t_list **stack)
{
	t_node	*ret;

	if (!stack || !*stack)
		return (NULL);
	ret = (*stack)->tail;
	(*stack)->tail = (*stack)->tail->prev;
	(*stack)->tail->next = NULL;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

int 		push(t_list **stack, void *data, size_t size)
{
	t_node	*node;

	if (!stack)
		return (FAILURE);
	node = new_node(data, size);
	if (!(*stack)->tail)
	{
		(*stack)->head = node;
		(*stack)->tail = node;
		(*stack)->tail->prev = NULL;
		(*stack)->tail->next = NULL;
		(*stack)->len++;
		return (SUCCESS);
	}
	(*stack)->tail->next = node;
	node->prev = (*stack)->tail;
	(*stack)->tail = node;
	(*stack)->len++;
	return (SUCCESS);
}