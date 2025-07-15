#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

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
		ft_free(args);
}

static void	stack_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
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
		stack_free(stack_a);
		stack_free(stack_b);
		return (0);
	}
	*stack_a = 0;
	*stack_b = 0;
	stack_init(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		stack_free(stack_a);
		stack_free(stack_b);
		return (0);
	}
	stack_sort(stack_a, stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
