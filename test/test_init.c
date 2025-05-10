/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:26:50 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/10 16:47:48 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	size_t	i;

	if (ac < 5 || ac > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (init_program(&data, ++av) == EXIT_FAILURE)
	{
		printf("Failed to initialize program\n");
		return (EXIT_FAILURE);
	}
	/* Código para imprimir informações para verificação */
	printf("Number of philosophers: %zu\n", data.philo_count);
	printf("Time to die: %zu ms\n", data.time_to_die);
	printf("Time to eat: %zu ms\n", data.time_to_eat);
	printf("Time to sleep: %zu ms\n", data.time_to_sleep);
	printf("Number of times each philosopher must eat: %zu\n", data.must_eat_count);
	/* Imprimir informações dos filósofos para verificação */
	i = 0;
	while (i < data.philo_count)
	{
		printf("Philosopher %zu: left fork = %p, right fork = %p\n",
			data.philos[i].id,
			(void*)data.philos[i].l_fork,
			(void*)data.philos[i].r_fork);
		i++;
	}
	clean_all(&data);
	return (EXIT_SUCCESS);
}
