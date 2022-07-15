#include "push_swap.h"

static void	rotate_reverse(t_list *list)
{
	if (list->size < 2)
		return ;
	list->bottom = list->bottom->prev;
	list->top = list->top->prev;
}

void	rra(t_lists *lists)
{
	rotate_reverse(lists->a);
	write(1, "rra\n", 4);
}

void	rrb(t_lists *lists)
{
	rotate_reverse(lists->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_lists *lists)
{
	rotate_reverse(lists->a);
	rotate_reverse(lists->b);
	write(1, "rrr\n", 4);
}
