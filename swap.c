/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:51 by sujpark           #+#    #+#             */
/*   Updated: 2022/07/16 11:56:40 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sa(t_lists *lists, int isChecker)
{
	swap(lists->a);
	if (!isChecker)
		write(1, "sa\n", 3);
}

void	sb(t_lists *lists, int isChecker)
{
	swap(lists->b);
	if (!isChecker)
		write(1, "sb\n", 3);
}

void	ss(t_lists *lists, int isChecker)
{
	swap(lists->a);
	swap(lists->b);
	if (!isChecker)
		write(1, "ss\n", 3);
}
