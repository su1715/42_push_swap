/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:38 by sujpark           #+#    #+#             */
/*   Updated: 2022/07/16 11:58:59 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_list *list)
{
	if (list->size < 2)
		return ;
	list->bottom = list->bottom->prev;
	list->top = list->top->prev;
}

void	rra(t_lists *lists, int isChecker)
{
	rotate_reverse(lists->a);
	if (!isChecker)
		write(1, "rra\n", 4);
}

void	rrb(t_lists *lists, int isChecker)
{
	rotate_reverse(lists->b);
	if (!isChecker)
		write(1, "rrb\n", 4);
}

void	rrr(t_lists *lists, int isChecker)
{
	rotate_reverse(lists->a);
	rotate_reverse(lists->b);
	if (!isChecker)
		write(1, "rrr\n", 4);
}
