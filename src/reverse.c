#include "push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (0);
	first = *stack;
	last = ft_lstlast(*stack);
	while (first)
	{
		if (first->next->next == 0)
		{
			first->next = 0;
			break ;
		}
		first = first->next;
	}
	last->next = *stack;
	*stack = last;
	return (1);
}

int	rra(t_list **stack_a)
{
	if (!reverse_rotate(stack_a))
		return (0);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_list **stack_b)
{
	if (!reverse_rotate(stack_b))
		return (0);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!(reverse_rotate(stack_a)) || !(reverse_rotate(stack_b)))
		return (0);
	ft_putendl_fd("rrr", 1);
	return (1);
}
