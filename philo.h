/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:54:32 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/13 21:01:34 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILOSOPHERS 200
# define MIN_TIME 60

typedef struct s_dinner_params
{
	int				num_of_philosophers;
	int				time_to_expire;
	int				eating_duration;
	int				sleeping_duration;
	int				required_meals;
	bool			all_finished_eating;
	bool			a_philosopher_died;
	time_t			start_of_dinner;
	pthread_mutex_t	display_mtx;
	pthread_mutex_t	death_mtx;
	pthread_mutex_t	meal_count_mtx;
	pthread_mutex_t	*utensils;
}	t_dinner_params;

typedef struct s_philosopher
{
	int			philosopher_id;
	int			meals_consumed;
	time_t		last_meal_timestamp;
	int			left_utensil;
	int			right_utensil;
	t_dinner_params	*shared_data;
}	t_philosopher;

int		ft_strlen(char *str);
int		is_digit(int c);
int		is_space(int c);
int		ft_atoi(char *str);
void	ft_putstr_fd(int fd, char *str);
void	log_utensil_pickup(t_philosopher *philo, int id);
void	log_eating(t_philosopher *philo, int id);
void	log_sleeping(t_philosopher *philo, int id);
void	log_thinking(t_philosopher *philo, int id);
void	log_death(t_philosopher *philo, int id);
void	display_error_msg(char *message);
bool	initialize_all_data(t_dinner_params *params, t_philosopher **philos, char **args);
void	monitor_dinner(t_philosopher *philos);
bool	validate_arguments(int count, char **args);
bool	validate_values(char **args);
void	*philo_cycle(void *arg);
bool	create_philosopher_threads(t_philosopher *philos, pthread_t *threads);
bool	join_philosopher_threads(t_philosopher *philos, pthread_t *threads);
time_t	get_elapsed_time(time_t start_time);
time_t	get_time_ms(void);
bool	is_dinner_ongoing(t_philosopher *philo);
void	ft_ms_sleep(time_t milliseconds, t_philosopher *philo);
void	destroy_all_mutexes(t_dinner_params *params);
void	cleanup_resources(t_dinner_params *params, t_philosopher **philos, pthread_t **threads);

#endif