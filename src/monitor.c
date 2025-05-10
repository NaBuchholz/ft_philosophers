/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/10 17:16:42 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_simulation_over(t_data *data)
{
	int result;

	pthread_mutex_lock(&data->dead_mutex);
	result = data->is_dead;
	pthread_mutex_unlock(&data->dead_mutex);
	return (result);
}
