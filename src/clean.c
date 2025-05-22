/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:32 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/22 18:05:44 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	clean_mutex(pthread_mutex_t *mutex)
{
	if (mutex == NULL)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(mutex) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	join_philosopher_threads(t_philo *philos, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (philos[i].thread)
			pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	clean_philos(t_philo *philos)
{
	if (philos)
		free(philos);
	return (EXIT_SUCCESS);
}

int	clean_all(t_data *data)
{
	size_t	i;

	if (!data)
		return (1);
	pthread_mutex_lock(&data->dead_mutex);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->dead_mutex);
	if (data->philos)
		join_philosopher_threads(data->philos, data->philo_count);
	if (data->forks)
	{
		i = 0;
		while (i < data->philo_count)
			clean_mutex(&data->forks[i++]);
		free(data->forks);
	}
	clean_mutex(&data->dead_mutex);
	clean_mutex(&data->print_mutex);
	if (data->philos)
		clean_philos(data->philos);
	return (EXIT_SUCCESS);
}
