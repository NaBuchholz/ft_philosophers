/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:30:00 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/10 15:14:46 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int main(int ac, char **av)
{
	t_data data;

	if (ac < 5 || ac > 6)
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}

	// Inicializar data
	if (!init_data(&data))
	{
		printf("Failed to initialize data\n");
		return (1);
	}

	// Analisar argumentos
	if (!parse_args(++av, &data))
	{
		printf("Failed to parse arguments\n");
		return (1);
	}

	// Imprimir informações para verificação
	printf("Number of philosophers: %zu\n", data.philo_count);
	printf("Time to die: %zu ms\n", data.time_to_die);
	printf("Time to eat: %zu ms\n", data.time_to_eat);
	printf("Time to sleep: %zu ms\n", data.time_to_sleep);
	printf("Number of times each philosopher must eat: %zu\n", data.must_eat_count);

	// Inicializar mutexes (se não for chamado dentro de init_data)
	if (!init_mutexes(&data))
	{
		printf("Failed to initialize mutexes\n");
		return (1);
	}

	// Inicializar filósofos (se não for chamado dentro de init_data)
	if (!init_philos(&data))
	{
		printf("Failed to initialize philosophers\n");
		return (1);
	}

	// Imprimir informações dos filósofos para verificação
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

	// clean_all(&data);

	return (0);
}
