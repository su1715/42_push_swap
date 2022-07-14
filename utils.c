#include "push_swap.h"
#include <limits.h>

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

long long	ft_atoll(const char *str)
{
	long long	tot;
	int				sign;

	tot = 0;
	sign = 1 - ((*str == '-') << 1);
	while (is_space(*str))
		str++;
	str += (*str == '-' || *str == '+');
	while (*str >= '0' && *str <= '9')
	{
		if (tot > (long long) LONG_MAX / 10 + (sign < 0))
			return ((sign < 0) - 1);
		tot = tot * 10;
		if (tot > (long long) LONG_MAX - (*str - '0') + (sign < 0))
			return ((sign < 0) - 1);
		tot += (*str - '0');
		str++;
	}
	return (tot * sign);
}

int	ft_isnum(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
