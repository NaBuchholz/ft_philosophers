/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:40 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/09 09:35:59 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}
	init_data(&data);
	if(!parse_args(++av, ac, &data))
		return(1);
	printf("Hello Philo!\n");
	return (0);
	//number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
	//          1                 2            3            4                   5*
}
