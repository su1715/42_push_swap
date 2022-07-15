#include "push_swap.h"

static void	swap(t_list *list)
{
	int	tmp_num;
	int	tmp_index;

	if (list->size < 2)
		return ;
	tmp_num = list->top->num;
	list->top->num = list->top->next->num;
	list->top->next->num = tmp_num;
	tmp_index = list->top->index;
	list->top->index = list->top->next->index;
	list->top->next->index = tmp_index;
}

void	sa(t_lists *lists)
{
	swap(lists->a);
	write(1, "sa\n", 3);
}

void	sb(t_lists *lists)
{
	swap(lists->b);
	write(1, "sb\n", 3);
}

void	ss(t_lists *lists)
{
	sa(lists);
	sb(lists);
	write(1, "ss\n", 3);
}
