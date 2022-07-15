#include "push_swap.h"

// void	sort_small(t_lists *lists)
// {
// 	while (a->size > 3)
// 	{
// 		while (a->top->index >= get_mid_result(a))
// 			ra(a);
// 		pb(lists);
// 	}
// 	if (a->size == 2 || a->size == 3)
// 		sort_two_three(a);
// 	while (b->size > 0)
// 		pa(lists);
// 	if (a->top->index > __)
// 		sa(a);
// }

int	is_r(t_list *list, int standard)
{
	t_node	*head;
	int		h_location;

	head = list->top;
	h_location = 0;
	while (head->index > standard)
	{
		head = head->next;
		h_location++;
	}
	if (h_location < list->size / 2)
		return (1);
	else
		return (0);
}
#include <stdio.h>
void	a_to_b(t_lists *lists, int chunk)
{
	int	i;

	i = 0;
	while (lists->a->size != 0)
	{
		if (get_top(lists->a) <= i)
		{
			pb(lists);
			i++;
		}
		else if (get_top(lists->a) > i && get_top(lists->a) <= i + chunk)
		{
			pb(lists);
			rb(lists);
			i++;
		}
		else
		{
			if (is_r(lists->a, i + chunk))
				ra(lists);
			else
				rra(lists);
		}
	}
}

void	sort_b(t_lists *lists)
{
	t_node	*head;
	int		i;

	i = 0;
	head = lists->b->top;
	while (head->index != lists->b->size - 1)
	{
		head = head->next;
		i++;
	}
	if (i < lists->b->size / 2)
		while (lists->b->top != head)
			rb(lists);
	else
		while (lists->b->top != head)
			rrb(lists);
}

void	b_to_a(t_lists *lists)
{
	while (lists->b->size != 0)
	{
		sort_b(lists);
		pa(lists);
	}
}

#include <stdio.h>
void	sort_large(t_lists *lists)
{
	int x;
	int chunk;

	x = lists->a->size;
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
	printf("chunk: %d\n", chunk);
	a_to_b(lists, chunk);
	//b_to_a(lists);
}

void	sort_list(t_lists *lists)
{
	if (lists->a->size <= 5)
		;
		// sort_small(lists);
	else
		sort_large(lists);
}
