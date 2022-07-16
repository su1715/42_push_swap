/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:13 by sujpark           #+#    #+#             */
/*   Updated: 2022/07/16 14:12:31 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_node(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = 0;
	return (new_node);
}

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		exit(1);
	list->top = NULL;
	list->bottom = NULL;
	list->size = 0;
	return (list);
}

int	is_sorted(t_list *list)
{
	t_node	*tmp;

	tmp = list->top;
	while (1)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
		if (tmp->next == list->top)
			return (1);
	}
}
