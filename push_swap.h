#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				num;
	int				index;
}	t_node;

typedef struct s_list {
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
}	t_list;

typedef struct s_lists {
	t_list	*a;
	t_list	*b;
}	t_lists;

t_list	*input(int ac, char *av[]);
long long	ft_atoll(const char *str);
int	ft_isnum(const char *s);
void	error_exit(void);
void	push(t_list *list, t_node *node);
void	sort_list(t_lists *lists);
int	get_top(t_list *list);
t_list	*init_list();

void	pa(t_lists *lists);
void	pb(t_lists *lists);
void	ra(t_lists *lists);
void	rb(t_lists *lists);
void	rra(t_lists *lists);
void	rrb(t_lists *lists);

#endif
