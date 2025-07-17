/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:22:25 by wshoweky          #+#    #+#             */
/*   Updated: 2025/07/17 16:22:27 by wshoweky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*node;
	t_list	*next;
	int		tmpv;
	int		tmpi;

	if (!stack || !*stack || ft_lstsize(*stack) < 2)
		return (-1);
	node = *stack;
	next = node->next;
	if (!node || !next)
	{
		stack_free (stack);
		ft_error("Error");
	}
	tmpv = node->value;
	tmpi = node->index;
	node->value = next->value;
	node->index = next->index;
	next->value = tmpv;
	next->index = tmpi;
	return (0);
}

int	sa(t_list **stack)
{
	if (swap(stack))
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack)
{
	if (swap(stack))
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) || swap(stack_b))
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}
