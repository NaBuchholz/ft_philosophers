/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:35 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/10 14:15:26 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_data(t_data *data)
{
	data->philo_count = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->must_eat_count = 0;
	data->start_time = get_time();
	if (!data->start_time)
	{
		printf("Error: Unable to get start time\n");
		return (0);
	}
	return (1);
}

static int	init_single_mutex(pthread_mutex_t *mutex)
{
	return (pthread_mutex_init(mutex, NULL) == 0);
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (0);//TODOLidar com falha na inicialização
	while (i < data->philo_count)
	{
		if (!init_single_mutex(&data->forks[i]))
		{
			//TODOfuncao de falha
			return (0);
		}
		i++;
	}
	if (!init_single_mutex(&data->print_mutex)
		|| !init_single_mutex(&data->dead_mutex))
	{
		//TODOLidar com falha na inicialização
		return (0);
	}
	data->is_dead = 0;
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return (0);//TODOLidar com falha na inicialização
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
	return (1);
}
