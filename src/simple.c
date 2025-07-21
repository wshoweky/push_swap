
#include "push_swap.h"

static int	get_min(t_list **stack)
{
	t_list	*node;
	int		min;

	node = *stack;
	min = node->index;
	while (node->next)
	{
		node = node->next;
		if (node->index < min)
			min = node->index;
	}
	return (min);
}

static void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && a > c && b < c)
		ra(stack);
	else if (a < b && a > c && c < b)
		rra(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a < b && a < c && b > c)
	{
		sa(stack);
		ra(stack);
	}
}

static void	sort_small(t_list **stack_a, t_list **stack_b, int size)
{
	int	min;
	int	distance;

	if (size == 2)
	{
		if (!is_sorted(stack_a))
			sa(stack_a);
		return ;
	}
	if (size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	min = get_min(stack_a);
	distance = get_distance(stack_a, min);
	make_top(stack_a, distance);
	pb(stack_b, stack_a);
	sort_small(stack_a, stack_b, size - 1);
	pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	sort_small(stack_a, stack_b, size);
}
