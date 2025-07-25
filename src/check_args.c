
#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit (1);
}

static int	ft_duplicates(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isnum(char *num)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = ft_atoi(num);
	if (ft_strlen(num) > 11)
	{
		if (nbr > INT_MAX || INT_MIN > nbr)
			return (0);
	}
	if (nbr > INT_MAX || INT_MIN > nbr)
		return (0);
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_check_nbr(char **args, int argc)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	if (argc > 2)
		i++;
	while (args[i])
	{
		nbr = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || !ft_duplicates(nbr, args, i))
		{
			if (argc == 2)
				ft_free_arg(args);
			ft_error("Error");
		}
		i++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	char		**args;

	if (argc < 2)
		exit (0);
	else if (argc == 2)
	{
		args = ft_split(argv[1], 32);
		if (!args || !args[0] || !*args[0])
		{
			ft_free_arg(args);
			ft_error("Error");
		}
	}
	else
		args = argv;
	ft_check_nbr(args, argc);
	if (argc == 2)
		ft_free_arg(args);
}
