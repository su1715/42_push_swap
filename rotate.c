#include "push_swap.h"

void	rotate(t_list *list)
{
	if (list->size < 2)
		return ;
	list->top = list->top->next;
	list->bottom = list->bottom->next;
}

void	ra(t_lists *lists)
{
	rotate(lists->a);
	write(1, "ra\n", 3);
}

void	rb(t_lists *lists)
{
	rotate(lists->b);
	write(1, "rb\n", 3);
}

void	rr(t_lists *lists)
{
	ra(lists);
	rb(lists);
	write(1, "rr\n", 3);
}
