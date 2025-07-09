/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:19:29 by wshoweky          #+#    #+#             */
/*   Updated: 2025/07/09 15:31:06 by wshoweky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_init(t_list **stack_a, int argc, char **argv)
{
	t_list	*node;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
	{
		i++;
		args = argv;
	}
	while (args[i])
	{
		node = new_node(ft_atoi(args[i]));
		list_add(stack, node);
		i++;
	}
	stack_index(stack);
	if (argc == 2)
		ft_free(args);
}

static void	stack_sort(t_list **stack_a, t_list **stack_b)
{
	if (list_size(*stack_a) <= 5)
		mini_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (404);
	ft_check(argc, argv);
	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	//if !!
	*stack_a = 0;
	*stack_b = 0;
	stack_init(stack_a, argc, argv);
	if(is_sorted(stack_a))
	{
		stack_free(stack_a);
		stack_free(stack_b);
		return (0);
	}
	stack_sort(stack_a, stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return(0);
}
