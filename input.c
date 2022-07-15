#include "push_swap.h"

static int	check_duplicate(t_list *a, t_node *node)
{
	t_node	*head;

	if (a->size == 0)
		return (0);
	head = a->top;
	while (1)
	{
		if (head->num < node->num)
			node->index++;
		else if (head->num > node->num)
			head->index++;
		else
			return (1);
		head = head->next;
		if (head == a->top)
			break;
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
	new_node->index = 0;
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
	new_node = make_node((int)num);
	if (check_duplicate(a, new_node))
		error_exit();
	push(a, new_node);
}

static void	split_input_str(const char *s, t_list *a)
{
	char	**sp;
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		error_exit();
	sp = ft_split(s, ' ');
	if (!sp)
		exit(1);
	i = 0;
	while (sp[i] != NULL)
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
	a = init_list();
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
