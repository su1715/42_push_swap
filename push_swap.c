#include "push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

#include <stdio.h>

void	test(t_list	*a)
{
	t_node	*head;

	head = a->top;
	while(head != a->bottom) {
		printf("%d ", head->num);
		head = head->next;
	}
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
	test(lists->a);
	return (0);
}
