#include "push_swap.h"

#include <stdio.h>
void	parse_test(t_list	*a)
{
	t_node	*head;

	if (a->size == 0)
		return;
	head = a->top;
	printf("(index: %d, num: %d), ", head->index, head->num);
	head = head->next;
	while(head != a->top) {
		printf("(index: %d, num: %d), ", head->index, head->num);
		head = head->next;
	}
	printf("\n");
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

int	main(int ac, char *av[])
{
	t_lists *lists;

	if (ac < 2)
		return (0);
	lists = (t_lists *)malloc(sizeof(t_lists));
	if (!lists)
		exit(1);
	lists->a = input(ac, av);
	lists->b = init_list();
	sort_list(lists);
	free_t_lists(lists);
	return (0);
}
