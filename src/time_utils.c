/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:11:04 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/20 16:54:34 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long time_in_ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time_in_ms)
		usleep(500);
}

size_t	time_diff(long long past)
{
	return (get_time() - past);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && (s1[count] || s2[count]))
	{
		if (s1[count] != s2[count])
			return (((unsigned char)s1[count]) - ((unsigned char)s2[count]));
		else
			count++;
	}
	return (0);
}
