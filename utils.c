/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:24:30 by wshoweky          #+#    #+#             */
/*   Updated: 2025/07/17 16:26:43 by wshoweky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **args)
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
/*
void make_top_direct(t_list **stack, int distance)
{
    if (distance == 0 || !stack || !*stack)
        return;
    t_list *prev = NULL;
    t_list *curr = *stack;
    int i = 0;
    // Find the node at 'distance'
    while (curr && i < distance) {
        prev = curr;
        curr = curr->next;
        i++;
    }
    if (!curr)
        return; // distance out of bounds
    // prev is the node before 'curr', curr is the node to move to top
    if (prev)
        prev->next = curr->next;
    else
        return; // already at top
    // Move curr to the front
    curr->next = *stack;
    *stack = curr;
}

void print_stack_debug(t_list **stack, const char *label)
{
    t_list *node = *stack;
    printf("%s: ", label);
    while (node)
    {
        printf("[%d|%d] ", node->value, node->index);
        node = node->next;
    }
    printf("\n");
}
*/
