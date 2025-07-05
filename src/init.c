/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:35 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/07/05 16:40:52 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_data(t_data *data)
{
	data->philo_count = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->must_eat_count = 0;
	data->forks = NULL;
	data->philos = NULL;
	data->start_time = get_time();
	if (!data->start_time)
	{
		printf("Error: Unable to get start time\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_single_mutex(pthread_mutex_t *mutex)
{
	return (pthread_mutex_init(mutex, NULL) == 0);
}

static int	init_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (EXIT_FAILURE);
	while (i < data->philo_count)
	{
		if (!init_single_mutex(&data->forks[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (!init_single_mutex(&data->print_mutex)
		|| !init_single_mutex(&data->dead_mutex))
		return (EXIT_FAILURE);
	data->is_dead = 0;
	return (EXIT_SUCCESS);
}

static int	init_philos(t_data *data)
{
	size_t	i;

	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].eating = 0;
		data->philos[i].r_fork = &data->forks[(i + 1) % data->philo_count];
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].data = data;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_program(t_data *data, char **av)
{
	if (init_data(data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (parse_args(av, data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_mutexes(data) != EXIT_SUCCESS)
	{
		clean_all(data);
		return (EXIT_FAILURE);
	}
	if (init_philos(data) != EXIT_SUCCESS)
	{
		clean_all(data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
