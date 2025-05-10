/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:28 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/10 17:20:14 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!is_simulation_over(philo->data))
		printf("%lld %d %s\n", time_diff(philo->data->start_time),
			philo->id, message);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	take_forks(t_philo *philo)
{

}

void	philo_eat(t_philo *philo)
{

}

void	philo_sleep(t_philo *philo)
{

}

void philo_think(t_philo *philo)
{

}
