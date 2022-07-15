/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:04 by sujpark           #+#    #+#             */
/*   Updated: 2022/07/15 22:34:05 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_t_list(t_list *list)
{
	t_node	*tmp;

	if (list->size)
	{
		list->bottom->next = NULL;
		list->bottom = NULL;
		while (1)
		{
			tmp = list->top;
			list->top = list->top->next;
			free(tmp);
			if (!list->top)
				break ;
		}
	}
	free(list);
}

void	free_t_lists(t_lists *lists)
{
	free_t_list(lists->a);
	free_t_list(lists->b);
	free(lists);
}
