/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyx <nyx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:22:45 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/05/12 16:58:22 by nyx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	size_t				meals_eaten;
	size_t				last_meal;
	size_t				id;
	int					eating;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	long long			start_time;
	size_t				philo_count;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				must_eat_count;
	int					is_dead;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		dead_mutex;
	t_philo				*philos;
}						t_data;

int						parse_args(char **av, t_data *data);
int						init_program(t_data *data, char **av);
long long				get_time(void);
int						clean_all(t_data *data);
long long				get_time(void);
size_t					time_diff(long long past);
void					ft_usleep(long long time_in_ms);
int						is_simulation_over(t_data *data);
void					philo_eat(t_philo *philo);
void					print_status(t_philo *philo, char *message);
void					take_forks(t_philo *philo);
void					philo_sleep(t_philo *philo);
void					philo_think(t_philo *philo);
int						create_philosophers(t_data *data);
void					monitor_philosophers(t_data *data);
void					print_error(char *msg);
int						is_all_numeric(char *str);
size_t					ft_atosize_t(char *str);
#endif