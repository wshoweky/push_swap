/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:07:25 by wshoweky          #+#    #+#             */
/*   Updated: 2025/07/17 17:35:00 by wshoweky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
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
	long long	tmp;

	i = 0;
	tmp = ft_atoi(num);
	if (tmp < -2147483648 || tmp > 2147483647)
		return (0);
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	check_nbr(char **args, long long nbr, int argc, int i)
{
	while (args[i])
	{
		nbr = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || !ft_duplicates(nbr, args, i))
		{
			if (argc == 2)
				ft_free(args);
			ft_error("Error");
		}
		i++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	int			i;
	char		**args;
	long long	nbr;

	i = 0;
	nbr = 0;
	if (argc < 2)
		exit (0);
	if (argc == 2)
	{
		args = ft_split(argv[1], 32);
		if (!args || !args[0] || !*args[0])
		{
			ft_free(args);
			ft_error("Error");
		}
	}
	else
	{
		i++;
		args = &argv[1];
	}
	check_nbr(args, nbr, argc, i);
	if (argc == 2)
		ft_free(args);
}
/*
		if (!ft_duplicates(tmp, args, i))
		{
			if (argc == 2)
				ft_free(args);
			ft_error("Error");
		}			
static int ft_isspace(char *str)
{
	int i = 0;
    //if (!str)
      //  return (1);
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
            str[i] != '\r' && str[i] != '\v' && str[i] != '\f')
            return 0;
        i++;
    }
    return 1;
}
static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}


void	ft_check_args(int argc, char **argv)
{
	int		i;
	long long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (!ft_duplicates(tmp, args, i))
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
*/
