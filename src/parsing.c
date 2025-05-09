/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:51 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/08 21:16:23 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	int	result;

	result = 0;
	if (c >= 48 && c <= 57)
		result = 2048;
	return (result);
}

int	ft_atoi(const char *str)
{
	size_t	count;
	int		sign_aux;
	int		result;

	sign_aux = 1;
	count = 0;
	result = 0;
	while (ft_isspace(str[count]))
		count++;
	if (str[count] == 43 && str[count + 1] != 45)
		count++;
	if (str[count] == 45)
	{
		sign_aux *= -1;
		count++;
	}
	while (ft_isdigit(str[count]))
	{
		result *= 10;
		result += str[count] - 48;
		count++;
	}
	return (result *= sign_aux);
}

void	parse_args(char **av, int ac, t_philo *philo)
{
	int		i;
	int		num;

	philo->args = malloc((ac - 1) * sizeof (int));
	if (philo->args == NULL)
		exit(1);
	i = 0;
	while (av[i])
	{
		num = 0;
		num = ft_atoi(av[i]);
		if (!num || num <= 0)
			exit(2);
		philo->args[i] = num;
		i++;
	}
}
