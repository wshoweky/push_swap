/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:03:45 by wshoweky          #+#    #+#             */
/*   Updated: 2025/07/17 18:09:03 by wshoweky         ###   ########.fr       */
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
		node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, node);
		i++;
	}
	stack_index(stack_a);
	if (argc == 2)
		ft_free_arg(args);
}

static void	stack_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	if (is_sorted(stack_a))
	{
		ft_free_ab(stack_a, stack_b);
		exit (0);
	}
	size = ft_lstsize(*stack_a);
	if (size <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	ft_check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
	{
		ft_free_ab(stack_a, stack_b);
		return (0);
	}
	*stack_a = 0;
	*stack_b = 0;
	stack_init(stack_a, argc, argv);
	//print_stack_debug(stack_a, "Before sort");
	stack_sort(stack_a, stack_b);
	//print_stack_debug(stack_a, "After sort");
	ft_free_ab(stack_a, stack_b);
	return (0);
}
