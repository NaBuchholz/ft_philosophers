/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:28 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/07/05 16:06:01 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *message)
{
	int	is_dead;

	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->dead_mutex);
	is_dead = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	if (!is_dead || ft_strncmp(message, "died", 4) == 0)
	{
		printf("%ld %ld %s\n", time_diff(philo->data->start_time),
			philo->id, message);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	philo->eating = 1;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->dead_mutex);
	print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->dead_mutex);
	philo->meals_eaten++;
	philo->eating = 0;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
	if (philo->data->philo_count % 2 != 0)
		ft_usleep(1);
}
