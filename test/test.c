/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:00:00 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/11 11:06:50 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* Teste para funções de tempo */
void	test_time_functions(void)
{
	long long	start;
	long long	after_sleep;
	long long	diff;

	printf("\n----- TESTING TIME FUNCTIONS -----\n");
	start = get_time();
	printf("Current time: %lld ms\n", start);

	printf("Testing ft_usleep with 100ms...\n");
	ft_usleep(100);
	after_sleep = get_time();
	diff = time_diff(start);

	printf("Time after sleep: %lld ms\n", after_sleep);
	printf("Time difference: %lld ms\n", diff);
	printf("Sleep accuracy: %s\n",
		(diff >= 100 && diff < 110) ? "GOOD" : "NEEDS IMPROVEMENT");
}

/* Testa impressão de status */
void	test_status_printing(t_data *data)
{
	printf("\n----- TESTING STATUS PRINTING -----\n");
	if (data->philo_count > 0)
	{
		t_philo *philo = &data->philos[0];
		printf("Testing status messages for philosopher 1:\n");
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		print_status(philo, "is sleeping");
		print_status(philo, "is thinking");
	}
}

/* Testa atribuição de garfos */
void	test_fork_assignment(t_data *data)
{
	size_t	i;

	printf("\n----- TESTING FORK ASSIGNMENTS -----\n");
	printf("Testing fork assignments for each philosopher:\n");
	i = 0;
	while (i < data->philo_count)
	{
		printf("Philosopher %zu:\n", data->philos[i].id);
		printf("  Left fork address: %p\n", (void *)data->philos[i].l_fork);
		printf("  Right fork address: %p\n", (void *)data->philos[i].r_fork);

		/* Verificar se garfos estão corretamente atribuídos */
		if (data->philos[i].l_fork == &data->forks[i])
			printf("  Left fork correctly assigned ✓\n");
		else
			printf("  Left fork incorrectly assigned ✗\n");

		if (data->philos[i].r_fork == &data->forks[(i + 1) % data->philo_count])
			printf("  Right fork correctly assigned ✓\n");
		else
			printf("  Right fork incorrectly assigned ✗\n");

		i++;
	}
}

/* Testa mutex dos garfos */
void	test_mutex_operations(t_data *data)
{
	int	result;

	printf("\n----- TESTING MUTEX OPERATIONS -----\n");
	if (data->philo_count > 0)
	{
		printf("Testing mutex lock/unlock on first fork:\n");

		printf("Locking mutex...\n");
		result = pthread_mutex_lock(&data->forks[0]);
		printf("pthread_mutex_lock result: %d %s\n",
			result, result == 0 ? "(Success)" : "(Failed)");

		printf("Unlocking mutex...\n");
		result = pthread_mutex_unlock(&data->forks[0]);
		printf("pthread_mutex_unlock result: %d %s\n",
			result, result == 0 ? "(Success)" : "(Failed)");
	}
}

/* Função para testar a simulação básica */
void	*test_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Philosopher %zu started routine\n", philo->id);

	take_forks(philo);
	philo_eat(philo);
	philo_sleep(philo);
	philo_think(philo);

	printf("Philosopher %zu completed routine\n", philo->id);
	return (NULL);
}

/* Testa uma simulação básica com um filósofo */
void	test_basic_simulation(t_data *data)
{
	pthread_t	test_thread;

	printf("\n----- TESTING BASIC SIMULATION -----\n");

	if (data->philo_count > 0)
	{
		printf("Running basic simulation with philosopher 1...\n");

		if (pthread_create(&test_thread, NULL, test_routine, &data->philos[0]) != 0)
		{
			printf("Error creating test thread\n");
			return;
		}

		pthread_join(test_thread, NULL);
		printf("Basic simulation completed\n");
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Error: invalid number of arguments\n");
		printf("Usage: %s <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n", av[0]);
		return (EXIT_FAILURE);
	}

	printf("----- PHILOSOPHERS TEST SUITE -----\n\n");
	printf("Initializing program with arguments: ");
	printf("%s %s %s %s", av[1], av[2], av[3], av[4]);
	if (ac == 6)
		printf(" %s", av[5]);
	printf("\n");

	if (init_program(&data, ++av) == EXIT_FAILURE)
	{
		printf("Failed to initialize program\n");
		return (EXIT_FAILURE);
	}

	/* Informações básicas */
	printf("\n----- PROGRAM CONFIGURATION -----\n");
	printf("Number of philosophers: %zu\n", data.philo_count);
	printf("Time to die: %zu ms\n", data.time_to_die);
	printf("Time to eat: %zu ms\n", data.time_to_eat);
	printf("Time to sleep: %zu ms\n", data.time_to_sleep);
	printf("Number of times each philosopher must eat: %zu\n", data.must_eat_count);
	printf("Start time: %lld\n", data.start_time);

	/* Testar cada componente */
	test_time_functions();
	test_status_printing(&data);
	test_fork_assignment(&data);
	test_mutex_operations(&data);

	/* Teste da simulação básica - descomente quando as outras funções estiverem finalizadas */
	test_basic_simulation(&data);

	printf("\n----- CLEANUP -----\n");
	printf("Cleaning up resources...\n");
	clean_all(&data);
	printf("Cleanup completed.\n");

	printf("\n----- TEST COMPLETE -----\n");
	return (EXIT_SUCCESS);
}
