/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyx <nyx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:51 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/12 16:34:16 by nyx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check_all_digits(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_valid_number(char *str)
{
	if (!str || !str[0])
		return (0);
	if (str[0] == '-')
		return (0);
	if (str[0] == '+' && !str[1])
		return (0);
	if (str[0] == '+')
		str++;
	if (!check_all_digits(str))
		return (0);
	return (1);
}

static int	check_valid_args(char **av)
{
	if (!check_valid_number(av[0]) || !check_valid_number(av[1])
		|| !check_valid_number(av[2]) || !check_valid_number(av[3]))
	{
		printf("Error: values must be positive integers\n");
		return (EXIT_FAILURE);
	}
	if (ft_atosize_t(av[0]) > 200)
	{
		printf("Error: max of 200 philosophers!\n");
		return (EXIT_FAILURE);
	}
	if (av[4] && !check_valid_number(av[4]))
	{
		printf("Error: values must be positive integers\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_args(char **av, t_data *data)
{
	if (check_valid_args(av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_atosize_t(av[0]) == 0 || ft_atosize_t(av[1]) == 0
		|| ft_atosize_t(av[2]) == 0 || ft_atosize_t(av[3]) == 0)
	{
		printf("Error: values must be positive integers\n");
		return (EXIT_FAILURE);
	}
	data->philo_count = ft_atosize_t(av[0]);
	data->time_to_die = ft_atosize_t(av[1]);
	data->time_to_eat = ft_atosize_t(av[2]);
	data->time_to_sleep = ft_atosize_t(av[3]);
	data->must_eat_count = 0;
	if (av[4])
	{
		if (ft_atosize_t(av[4]) == 0)
			return (EXIT_FAILURE);
		data->must_eat_count = ft_atosize_t(av[4]);
	}
	return (EXIT_SUCCESS);
}
