/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:59:43 by wshoweky          #+#    #+#             */
/*   Updated: 2025/07/17 17:30:35 by wshoweky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	/*
	t_list	*node;
	int		max_index;
	int		max_bits;

	node = *stack;
	max_index = node->index;
	max_bits = 0;
	while (node)
	{
		if (node->index > max_index)
			max_index = node->index;
		node = node->next;
	}
		*/
	int	max_index;
	int	max_bits;

	max_bits = 0;
	max_index = ft_lstsize(*stack) - 1;
	while (max_index >> max_bits)
		max_bits++;
	return (max_bits);
}

static void	radix_sort_stack_b(t_list **stack_a, t_list **stack_b, int bit)
{
	int b_size = ft_lstsize(*stack_b);
	int n = 0;
	while (n < b_size)
	{
		if (((*stack_b)->index >> bit) & 1)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		n++;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		n;
	int		size;
	int		max_bits;

	i = 0;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		size = ft_lstsize(*stack_a);
		n = 0;
		while (n++ < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);			
		}		
		if (++i < max_bits)
			radix_sort_stack_b(stack_a, stack_b, i);		
	}	
	while (ft_lstsize(*stack_b))
		pa(stack_a, stack_b);
}
/*
// Helper to find the max index in stack
static int find_max_index(t_list **stack) {
    t_list *node = *stack;
    int max = node->index;
    while (node) {
        if (node->index > max)
            max = node->index;
        node = node->next;
    }
    return max;
}

// Helper to get the position of a given index in stack
static int get_position(t_list **stack, int index) {
    t_list *node = *stack;
    int pos = 0;
    while (node) {
        if (node->index == index)
            return pos;
        pos++;
        node = node->next;
    }
    return -1;
}

void chunk_sort(t_list **stack_a, t_list **stack_b, int chunk_count)
{
    int size = ft_lstsize(*stack_a);
    int chunk_size = size / chunk_count;
    int chunk_min, chunk_max, pos;

    for (int c = 0; c < chunk_count; c++)
    {
        chunk_min = c * chunk_size;
        chunk_max = (c == chunk_count - 1) ? size - 1 : (c + 1) * chunk_size - 1;
        int pushed = 0;
        while (pushed < chunk_size && ft_lstsize(*stack_a) > 0)
        {
            // Find position of next element in chunk
            t_list *node = *stack_a;
            pos = 0;
            while (node && !(node->index >= chunk_min && node->index <= chunk_max))
            {
                node = node->next;
                pos++;
            }
            if (!node)
                break;
            // Bring to top with minimal rotations
            if (pos <= ft_lstsize(*stack_a) / 2)
                while (pos-- > 0) ra(stack_a);
            else
                while (pos++ < ft_lstsize(*stack_a)) rra(stack_a);
            pb(stack_b, stack_a);
            pushed++;
        }
    }
    // Restore from B to A, always bring max to top
    while (ft_lstsize(*stack_b))
    {
        int max = find_max_index(stack_b);
        int pos = get_position(stack_b, max);
        if (pos <= ft_lstsize(*stack_b) / 2)
            while (pos-- > 0) rb(stack_b);
        else
            while (pos++ < ft_lstsize(*stack_b)) rrb(stack_b);
        pa(stack_a, stack_b);
    }
}

static int	get_max_bits(t_list **stack)
{
	t_list	*node;
	int		max_index;
	int		max_bits;

	node = *stack;
	max_index = node->index;
	max_bits = 0;
	while (node)
	{
		if (node->index > max_index)
			max_index = node->index;
		node = node->next;
	}
	while (max_index >> max_bits)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		n;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		n = 0;
		while (n < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
			n++;
		}
		while (ft_lstsize(*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
*/