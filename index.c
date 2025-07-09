/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:19:05 by wshoweky          #+#    #+#             */
/*   Updated: 2025/07/09 16:27:47 by wshoweky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*node;
	t_list	*min;
	int	has_min;

	min = 0;
	has_min = 0;
	node = *stack;
	while (node)
	{
		if ((node->index == -1) && (has_min == 0 || node->value < min->value))
		{
			min = node;
			has_min = 1;
		}
		node = node->next;
	}
	return(min);
}

void	stack_index(t_list **stack)
{
	t_list	*node;
	int	index;

	index = 0;
	node = get_next_min(stack);
	while (node)
	{
		node->index = index++;
		node = get_next_min(stack);
	}
}
