/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:40 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/10 13:33:12 by nbuchhol         ###   ########.fr       */
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
	if (!parse_args(++av, &data))
		return (1);
	printf("Hello Philo!\n");
	return (0);
}
