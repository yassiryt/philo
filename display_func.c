/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:53:49 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/13 21:00:40 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_utensil_pickup(t_philosopher *philo, int id)
{
	time_t	timestamp;

	pthread_mutex_lock(&philo->shared_data->display_mtx);
	timestamp = get_elapsed_time(philo->shared_data->start_of_dinner);
	if (!is_dinner_ongoing(philo))
	{
		pthread_mutex_unlock(&philo->shared_data->display_mtx);
		return ;
	}
	printf("\033[36m%ld %d has taken a utensil\033[0m\n", timestamp, id);
	pthread_mutex_unlock(&philo->shared_data->display_mtx);
}

void	log_eating(t_philosopher *philo, int id)
{
	time_t	timestamp;

	pthread_mutex_lock(&philo->shared_data->display_mtx);
	timestamp = get_elapsed_time(philo->shared_data->start_of_dinner);
	if (!is_dinner_ongoing(philo))
	{
		pthread_mutex_unlock(&philo->shared_data->display_mtx);
		return ;
	}
	printf("\033[32m%ld %d is eating\033[0m\n", timestamp, id);
	pthread_mutex_unlock(&philo->shared_data->display_mtx);
}

void	log_sleeping(t_philosopher *philo, int id)
{
	time_t	timestamp;

	pthread_mutex_lock(&philo->shared_data->display_mtx);
	timestamp = get_elapsed_time(philo->shared_data->start_of_dinner);
	if (!is_dinner_ongoing(philo))
	{
		pthread_mutex_unlock(&philo->shared_data->display_mtx);
		return ;
	}
	printf("\033[33m%ld %d is sleeping\033[0m\n", timestamp, id);
	pthread_mutex_unlock(&philo->shared_data->display_mtx);
}

void	log_thinking(t_philosopher *philo, int id)
{
	time_t	timestamp;

	pthread_mutex_lock(&philo->shared_data->display_mtx);
	timestamp = get_elapsed_time(philo->shared_data->start_of_dinner);
	if (!is_dinner_ongoing(philo))
	{
		pthread_mutex_unlock(&philo->shared_data->display_mtx);
		return ;
	}
	printf("\033[35m%ld %d is thinking\033[0m\n", timestamp, id);
	pthread_mutex_unlock(&philo->shared_data->display_mtx);
}

void	log_death(t_philosopher *philo, int id)
{
	time_t	timestamp;

	pthread_mutex_lock(&philo->shared_data->display_mtx);
	timestamp = get_elapsed_time(philo->shared_data->start_of_dinner);
	if (!is_dinner_ongoing(philo))
	{
		pthread_mutex_unlock(&philo->shared_data->display_mtx);
		return ;
	}
	printf("\033[31m%ld %d died\033[0m\n", timestamp, id);
	pthread_mutex_lock(&philo->shared_data->death_mtx);
	philo->shared_data->a_philosopher_died = true;
	pthread_mutex_unlock(&philo->shared_data->death_mtx);
	pthread_mutex_unlock(&philo->shared_data->display_mtx);
}