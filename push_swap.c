#include "push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

#include <stdio.h>

void	parse_test(t_list	*a)
{
	t_node	*head;

	head = a->top;
	printf("(index: %d, num: %d), ", head->index, head->num);
	head = head->next;
	while(head != a->top) {
		printf("(index: %d, num: %d), ", head->index, head->num);
		head = head->next;
	}
}

void	sort_small(t_lists *lists)
{

}

void	sort_large(t_lists *lists)
{
	a_to_b();
	b_to_a();
}

void	sort_list(t_lists *lists)
{
	if (lists->a->size < 5)
		sort_small(lists);
	else
		sort_large(lists);
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
	parse_test(lists->a);
	sort_list(lists);
	return (0);
}
