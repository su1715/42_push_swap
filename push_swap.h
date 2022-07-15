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

t_node		*make_node(int num);
t_list		*init_list();
t_list		*input(int ac, char *av[]);
void		sort_small(t_lists *lists);
void		sort_large(t_lists *lists);
int			is_rotate(t_list *list, int standard);
int			get_top(t_list *list);
int			ft_isnum(const char *s);
long long	ft_atoll(const char *str);
int			ft_numlen(long long n);
void		error_exit(void);
void		free_t_lists(t_lists *lists);
void		push(t_list *list, t_node *node);
void		rotate(t_list *list);
void		sa(t_lists *lists);
void		sb(t_lists *lists);
void		ss(t_lists *lists);
void		pa(t_lists *lists);
void		pb(t_lists *lists);
void		ra(t_lists *lists);
void		rb(t_lists *lists);
void		rr(t_lists *lists);
void		rra(t_lists *lists);
void		rrb(t_lists *lists);
void		rrc(t_lists *lists);

#endif
