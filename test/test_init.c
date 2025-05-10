/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:26:50 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/10 16:27:14 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
	t_data data;

	if (ac < 5 || ac > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}

	if (!init_program(&data, ++av))
	{
		printf("Failed to initialize program\n");
		return (1);
	}

	/* Código para imprimir informações para verificação */
	printf("Number of philosophers: %zu\n", data.philo_count);
	printf("Time to die: %zu ms\n", data.time_to_die);
	printf("Time to eat: %zu ms\n", data.time_to_eat);
	printf("Time to sleep: %zu ms\n", data.time_to_sleep);
	printf("Number of times each philosopher must eat: %zu\n", data.must_eat_count);

	/* Imprimir informações dos filósofos para verificação */
	int i;

	i = 0;
	while (i < data.philo_count)
	{
		printf("Philosopher %d: left fork = %p, right fork = %p\n",
			data.philos[i].id,
			(void*)data.philos[i].l_fork,
			(void*)data.philos[i].r_fork);
		i++;
	}

	clean_all(&data);

	return (0);
}
