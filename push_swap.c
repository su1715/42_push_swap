/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:34:30 by sujpark           #+#    #+#             */
/*   Updated: 2022/07/16 16:31:43 by sujpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_list(t_lists *lists)
{
	if (lists->a->size <= 5)
		sort_small(lists);
	else
		sort_large(lists);
}

int	main(int ac, char *av[])
{
	t_lists	*lists;

	if (ac < 2)
		return (0);
	lists = (t_lists *)malloc(sizeof(t_lists));
	if (!lists)
		exit(1);
	lists->a = input(ac, av);
	if (is_sorted(lists->a))
		exit(1);
	lists->b = init_list();
	sort_list(lists);
	free_t_lists(lists);
	return (0);
}
