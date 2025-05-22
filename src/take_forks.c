/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:02:12 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/22 18:19:12 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (is_simulation_over(philo->data))
	{
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	if (is_simulation_over(philo->data))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	print_status(philo, "has taken a fork");
}

static void	take_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (is_simulation_over(philo->data))
	{
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	if (is_simulation_over(philo->data))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	print_status(philo, "has taken a fork");
}

void	take_forks(t_philo *philo)
{
	if (is_simulation_over(philo->data))
		return ;
	if (philo->id % 2 == 0)
		take_forks_even(philo);
	else
		take_forks_odd(philo);
}
