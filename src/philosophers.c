/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:58 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/11 11:00:51 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!is_simulation_over(philo->data))
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
	return (NULL);
}
