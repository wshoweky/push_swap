#include "push_swap.h"

t_list	*ft_lstlast(t_list *node)
{
	if (!node)
		return (0);
	while (node->next)
	{
		node = node->next;
		if (!(node->next))
			return (node);
	}
	return (0);
}

void	ft_lstadd_back(t_list **stack, t_list *node)
{
	t_list	*last;

	if (*stack)
	{
		last = ft_lstlast(*stack);
		last->next = node;
		node->next = 0;
	}
	else
	{
		*stack = node;
		node->next = 0;
	}
}

int	ft_lstsize(t_list *node)
{
	int	n;

	n = 0;
	while (node)
	{
		n++;
		node = node->next;
	}
	return (n);
}
