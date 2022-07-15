#include "push_swap.h"

int	is_rotate(t_list *list, int standard)
{
	t_node	*tmp;
	int		h_location;

	tmp = list->top;
	h_location = 0;
	while (tmp->index > standard)
	{
		tmp = tmp->next;
		h_location++;
	}
	if (h_location < list->size / 2)
		return (1);
	else
		return (0);
}

static void	a_to_b(t_lists *lists, int chunk)
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
			if (is_rotate(lists->a, i + chunk))
				ra(lists);
			else
				rra(lists);
		}
	}
}

static void	raise_b_last_index(t_lists *lists)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = lists->b->top;
	while (tmp->index != lists->b->size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < lists->b->size / 2)
		while (lists->b->top != tmp)
			rb(lists);
	else
		while (lists->b->top != tmp)
			rrb(lists);
}

static void	b_to_a(t_lists *lists)
{
	while (lists->b->size != 0)
	{
		raise_b_last_index(lists);
		pa(lists);
	}
}

void	sort_large(t_lists *lists)
{
	int x;
	int chunk;

	x = lists->a->size;
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
	a_to_b(lists, chunk);
	b_to_a(lists);
}
