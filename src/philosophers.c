/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:58 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/22 18:07:36 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "has taken a fork");
	ft_usleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

static void	philo_cycle(t_philo *philo)
{
	if (!is_simulation_over(philo->data))
		take_forks(philo);
	if (!is_simulation_over(philo->data))
		philo_eat(philo);
	if (!is_simulation_over(philo->data))
		philo_sleep(philo);
	if (!is_simulation_over(philo->data))
		philo_think(philo);
}

static void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->data->philo_count == 1)
		return (handle_single_philo(philo));
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!is_simulation_over(philo->data))
		philo_cycle(philo);
	return (NULL);
}

int	create_philosophers(t_data *data)
{
	size_t	i;

	if (!data->philos)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].last_meal = get_time();
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine,
				&data->philos[i]) != 0)
		{
			pthread_mutex_lock(&data->dead_mutex);
			data->is_dead = 1;
			pthread_mutex_unlock(&data->dead_mutex);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
