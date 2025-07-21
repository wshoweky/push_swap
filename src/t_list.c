
#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_lstadd_back(t_list **stack, t_list *node)
{
	t_list	*last;

	if (!stack || !node)
		return ;
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
	if (!node)
		return (0);
	while (node)
	{
		n++;
		node = node->next;
	}
	return (n);
}

void	ft_free_ab(t_list **a, t_list **b)
{
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
}
