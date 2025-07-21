
#include "push_swap.h"

void	ft_free_arg(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	stack_free(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	node = *stack;
	if (!stack)
		return ;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}

int	is_sorted(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node && node->next)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_distance(t_list **stack, int index)
{
	t_list	*node;
	int		distance;

	distance = 0;
	node = *stack;
	while (node)
	{
		if (node->index == index)
			break ;
		distance++;
		node = node->next;
	}
	return (distance);
}

void	make_top(t_list **stack, int distance)
{
	t_list	*node;
	int		tmp;
	int		size;

	if (!distance)
		return ;
	node = *stack;
	size = ft_lstsize(node);
	tmp = size - distance;
	if (distance <= (size / 2))
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack);
	}
}
