/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyx <nyx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:11:09 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/12 17:32:09 by nyx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_check_overflow(char *str)
{
	size_t	res;
	int		i;
	int		len;

	i = 0;
	len = 0;
	res = 0;
	if (str[i] == '+')
		i++;
	while (str[i + len] >= '0' && str[i + len] <= '9')
		len++;
	if (len > 10)
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > SIZE_MAX / 10)
			return (1);
		res = res * 10;
		if (res > SIZE_MAX - (str[i] - '0'))
			return (1);
		res = res + (str[i] - '0');
		i++;
	}
	return (0);
}

size_t	ft_atosize_t(char *str)
{
	size_t	result;
	int		i;

	if (!str || ft_check_overflow(str))
		return (0);
	result = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	print_error(char *msg)
{
	printf("Error: %s\n", msg);
}

int	is_all_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*temp_pt;

	temp_pt = (unsigned char *)s;
	while (len > 0)
	{
		*temp_pt = (unsigned char)c;
		temp_pt++;
		len--;
	}
	return (s);
}
