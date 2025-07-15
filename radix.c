/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:59:43 by wshoweky          #+#    #+#             */
/*   Updated: 2025/07/15 15:53:18 by wshoweky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_list	*node;
	int		i;
	int		n;
	int		size;
	int		max_bits;

	i = 0;
	node = *stack_a;
	size = ft_lstsize(node);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		n = 0;
		while (n++ < size)
		{
			if ((node->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		while (ft_lstsize(*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
