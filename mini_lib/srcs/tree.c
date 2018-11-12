#include "../incl/mini_lib.h"

t_tree	*new_tree(void)
{
	t_tree *tree;

	if (!(tree = (t_tree*)memalloc(sizeof(t_tree))))
		return (NULL);
	tree->len = 0;
	tree->children = NULL;
	return (tree);
}