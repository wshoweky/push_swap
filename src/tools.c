#include "push_swap.h"

void	print_stack_debug(t_list **stack, const char *label)
{
	t_list	*node;

	node = *stack;
	printf("%s: ", label);
	while (node)
	{
		printf("[%d|%d] ", node->value, node->index);
		node = node->next;
	}
	printf("\n");
}
/*
static int  ft_isok(char *str)
{
    long long   n;
    int sign;
    int i;

    n = 0;
    sign = 1;
    i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
            return (0);
    while (str[i])
    {
        if (ft_strlen(str) > 11 || *str == 0)
            return (0);
        if (str[i] < '0' || str[i] > '9')
            return (0);
        n = n * 10 + (str[i++] - '0');
        if ((sign == 1 && n > INT_MAX) || (sign == -1 && -n < INT_MIN))
            return (0);
    }
    return (1);
}

void	ft_check_overflow(char **args, int argc)
{
	int	n = 0;
	while (args[n])
	{
		if (!ft_isok(args[n]))
		{
			if (argc == 2)
				ft_free_arg(args);
			ft_error("Error");
		}
		n++;
	}	
}

int atolong(const char *ptr, int *overflow)
{
	int		sign;
	long	nbr;
	int		i;

	i = 0;
	nbr = 0;
	sign = 1;
	if (ptr[i] == '-')
		sign *= -1;
	if (ptr[i] == '+' || ptr[i] == '-')
		i++;
	while (ft_isdigit(ptr[i]))
	{
        nbr *= 10;
		nbr += ptr[i] - '0';
		i++;
	}
	nbr *= sign;
	if (nbr < INT_MIN || INT_MAX < nbr)
		*overflow = 1;
	return (nbr);
}

void	free_all(t_node *a, t_node *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}
*/
