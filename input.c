#include "push_swap.h"

static int	check_dup(t_list *a, int num)
{
	t_node	*head;

	if (a->size == 0)
		return (0);
	head = a->top;
	if (head->num == num)
			return (1);
	head = head->next;
	while (head != a->top)
	{
		if (head->num == num)
			return (1);
		head = head->next;
	}
	return (0);
}

t_node	*make_node(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	ft_numlen(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	check_input(const char *s, t_list *a)
{
	long long	num;
	t_node		*new_node;
	int			len;

	len = ft_strlen(s);
	len -= (s[0] == '-' || s[0] == '+');
	num = ft_atoll(s);
	if (!(ft_isnum(s) && len == ft_numlen(num)))
		error_exit();
	if (num > 2147483647 || num < -2147483648)
		error_exit();
	if (check_dup(a, (int)num))
		error_exit();
	new_node = make_node((int)num);
	push(a, new_node);
}

static void	split_input_str(const char *s, t_list *a)
{
	char	**sp;
	int		i;

	i = 0;
	sp = ft_split(s, ' ');
	if (!sp)
		exit(1);
	while (sp[i])
	{
		check_input(sp[i], a);
		free(sp[i]);
		i++;
	}
	free(sp);
}

t_list	*input(int ac, char *av[])
{
	t_list	*a;
	int		i;

	i = 1;
	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		exit(1);
	a->size = 0;
	a->bottom = NULL;
	a->top = NULL;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			split_input_str(av[i], a);
		else
			check_input(av[i], a);
		i++;
	}
	return (a);
}
