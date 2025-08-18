/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:54:40 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/15 04:07:47 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_take_forks(t_philosopher *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->left_fork;
	right_fork = philo->right_fork;
	pthread_mutex_lock(&philo->shared_data->forks[left_fork]);
	log_fork_pickup(philo, philo->philosopher_id);
	pthread_mutex_lock(&philo->shared_data->forks[right_fork]);
	log_fork_pickup(philo, philo->philosopher_id);
}

static void	philo_is_eating(t_philosopher *philo)
{
	philo->meals_consumed++;
	log_eating(philo, philo->philosopher_id);
	pthread_mutex_lock(&philo->shared_data->meal_count_mtx);
	philo->last_meal_timestamp = get_elapsed_time
		(philo->shared_data->start_of_dinner);
	pthread_mutex_unlock(&philo->shared_data->meal_count_mtx);
	ft_ms_sleep(philo->shared_data->eating_duration, philo);
	pthread_mutex_unlock(&philo->shared_data
		->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->shared_data
		->forks[philo->left_fork]);
}

static void	philo_is_sleeping(t_philosopher *philo)
{
	log_sleeping(philo, philo->philosopher_id);
	ft_ms_sleep(philo->shared_data->sleeping_duration, philo);
}

static void	philo_one_case(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->shared_data->forks[philo->left_fork]);
	log_fork_pickup(philo, philo->philosopher_id);
	pthread_mutex_unlock(&philo->shared_data->forks[philo->left_fork]);
	ft_ms_sleep(philo->shared_data->time_to_expire, philo);
	log_death(philo, philo->philosopher_id);
	pthread_mutex_lock(&philo->shared_data->death_mtx);
	philo->shared_data->a_philosopher_died = true;
	pthread_mutex_unlock(&philo->shared_data->death_mtx);
}

void	*philo_cycle(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	if (philo->shared_data->num_of_philosophers == 1)
	{
		philo_one_case(philo);
		return (NULL);
	}
	if (philo->philosopher_id % 2 == 0)
		ft_ms_sleep(50, philo);
	while (is_dinner_ongoing(philo))
	{
		philo_take_forks(philo);
		philo_is_eating(philo);
		philo_is_sleeping(philo);
		log_thinking(philo, philo->philosopher_id);
	}
	return (NULL);
}
