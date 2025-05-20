/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/20 16:58:33 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_simulation_over(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->dead_mutex);
	result = data->is_dead;
	pthread_mutex_unlock(&data->dead_mutex);
	return (result);
}

static int	check_if_philo_died(t_data *data, t_philo *philo)
{
	int	died;

	died = 0;
	pthread_mutex_lock(&data->dead_mutex);
	if (philo->eating == 0 && time_diff(philo->last_meal) > data->time_to_die)
	{
		data->is_dead = 1;
		died = 1;
	}
	pthread_mutex_unlock(&data->dead_mutex);
	if (died)
	{
		print_status(philo, "died");
		return (1);
	}
	return (0);
}

static int	check_if_all_ate_enough(t_data *data)
{
	size_t	i;
	int		all_ate;

	if (data->must_eat_count == 0)
		return (0);
	pthread_mutex_lock(&data->dead_mutex);
	all_ate = 1;
	i = 0;
	while (i < data->philo_count)
	{
		if (data->philos[i].meals_eaten < data->must_eat_count)
		{
			all_ate = 0;
			break ;
		}
		i++;
	}
	if (all_ate)
		data->is_dead = 1;
	pthread_mutex_unlock(&data->dead_mutex);
	return (all_ate);
}

void	monitor_philosophers(t_data *data)
{
	size_t	i;

	ft_usleep(1);
	while (!is_simulation_over(data))
	{
		i = 0;
		while (i < data->philo_count && !is_simulation_over(data))
		{
			if (check_if_philo_died(data, &data->philos[i]))
				break ;
			i++;
		}
		if (is_simulation_over(data))
			break ;
		if (check_if_all_ate_enough(data))
			break ;
		usleep(50);
	}
	ft_usleep(1);
}
