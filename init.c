#include "push_swap.h"

t_node	*make_node(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = 0;
	return (new_node);
}

t_list	*init_list()
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		exit(1);
	list->top = NULL;
	list->bottom = NULL;
	list->size = 0;
	return (list);
}
