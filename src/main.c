/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:40 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/12 11:19:02 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (init_program(&data, ++av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_philosophers(&data) == EXIT_FAILURE)
	{
		printf("Error: failed to create philosophers\n");
		clean_all(&data);
		return (EXIT_FAILURE);
	}
	monitor_philosophers(&data);
	clean_all(&data);
	return (EXIT_SUCCESS);
}
