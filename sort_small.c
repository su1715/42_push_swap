/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:48 by sujpark           #+#    #+#             */
/*   Updated: 2022/07/16 13:35:06 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_nodes(t_lists *lists)
{
	t_list	*a;

	a = lists->a;
	if (a->top->index > a->top->next->index)
		sa(lists, 0);
}

static void	sort_three_nodes(t_lists *lists, int first, int second, int third)
{
	if (first < second)
	{
		if (second > third && first < third)
		{
			rra(lists, 0);
			sa(lists, 0);
		}
		else if (second > third && first > third)
			rra(lists, 0);
	}
	else
	{
		if (second < third && first < third)
			sa(lists, 0);
		else if (second < third && first > third)
			ra(lists, 0);
		else if (second > third && first > third)
		{
			ra(lists, 0);
			sa(lists, 0);
		}
	}
}

static void	sort_more_nodes(t_lists *lists, int first, int second, int third)
{
	t_list	*a;
	t_list	*b;
	int		a_min_index;

	a = lists->a;
	b = lists->b;
	a_min_index = 0;
	while (a->size > 3)
	{
		if (is_rotate(a, a->size / 2))
			while (a->top->index != a_min_index)
				ra(lists, 0);
		else
			while (a->top->index != a_min_index)
				rra(lists, 0);
		pb(lists, 0);
		a_min_index++;
	}
	sort_three_nodes(lists, first, second, third);
	if (b->top->index < b->top->next->index)
		rb(lists, 0);
	while (b->size)
		pa(lists, 0);
}

void	sort_small(t_lists *lists)
{
	int	first;
	int	second;
	int	third;

	first = lists->a->top->index;
	second = lists->a->top->next->index;
	third = lists->a->top->next->next->index;
	if (lists->a->size < 2)
		return ;
	else if (lists->a->size == 2)
		sort_two_nodes(lists);
	else if (lists->a->size == 3)
		sort_three_nodes(lists, first, second, third);
	else
		sort_more_nodes(lists, first, second, third);
}
