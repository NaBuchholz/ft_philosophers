/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:51 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/12 11:03:57 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	int	result;

	result = 0;
	if (c >= 48 && c <= 57)
		result = 2048;
	return (result);
}

static int	ft_atoi(const char *str)
{
	size_t	count;
	int		result;

	count = 0;
	result = 0;
	while (ft_isspace(str[count]))
		count++;
	if (str[count] == 43)
		count++;
	while (ft_isdigit(str[count]))
	{
		result *= 10;
		result += str[count] - 48;
		count++;
	}
	return (result);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (EXIT_FAILURE);
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (EXIT_FAILURE);
		i++;
	}
	if (ft_atoi(str) <= 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_args(char **av, t_data *data)
{
	if (is_valid_number(av[0]) == EXIT_FAILURE
		|| is_valid_number(av[1]) == EXIT_FAILURE
		|| is_valid_number(av[2]) == EXIT_FAILURE
		|| is_valid_number(av[3]) == EXIT_FAILURE)
	{
		printf("Error: values must be positive integers\n");
		return (EXIT_FAILURE);
	}
	if (ft_atoi(av[0]) > 200)
	{
		printf("Error: max of 200 philosophers!\n");
		return (EXIT_FAILURE);
	}
	data->philo_count = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	if (av[4])
		data->must_eat_count = ft_atoi(av[4]);
	return (EXIT_SUCCESS);
}
