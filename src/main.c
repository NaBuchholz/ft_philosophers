/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:40 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/12 10:19:49 by nbuchhol         ###   ########.fr       */
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
	if (!init_program(&data, ++av))
		return (EXIT_FAILURE);
	if (create_philosophers(&data) != EXIT_SUCCESS)
	{
		printf("Error: failed to create philosophers\n");
		clean_all(&data);
		return (EXIT_FAILURE);
	}
	clean_all(&data);
	return (EXIT_SUCCESS);
}
