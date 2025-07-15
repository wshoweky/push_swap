#include "push_swap.h"

int	rotate(t_list	**stack)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (0);
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = 0;
	return (1);
}

int	ra(t_list **stack_a)
{
	if (!rotate(stack_a))
		return (0);
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_list **stack_b)
{
	if (!rotate(stack_b))
		return (0);
	ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (!(rotate(stack_a)) || !(rotate(stack_b)))
		return (0);
	ft_putendl_fd("rr", 1);
	return (1);
}
