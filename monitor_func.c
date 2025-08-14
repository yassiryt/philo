/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:54:18 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/13 21:04:32 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_for_death(t_philosopher *philos, t_dinner_params *params)
{
	int	i;

	i = 0;
	if (!is_dinner_ongoing(philos))
		return (false);
	while (i < params->num_of_philosophers)
	{
		pthread_mutex_lock(&params->meal_count_mtx);
		if (((get_elapsed_time(params->start_of_dinner) - philos[i].last_meal_timestamp)
				> params->time_to_expire))
		{
			pthread_mutex_unlock(&params->meal_count_mtx);
			log_death(&philos[i], philos[i].philosopher_id);
			pthread_mutex_lock(&params->death_mtx);
			params->a_philosopher_died = true;
			pthread_mutex_unlock(&params->death_mtx);
			return (true);
		}
		pthread_mutex_unlock(&params->meal_count_mtx);
		i++;
	}
	return (false);
}

static void	check_if_all_ate(t_philosopher *philos, t_dinner_params *params)
{
	int	i;

	i = 0;
	if (params->required_meals == -1)
		return ;
	pthread_mutex_lock(&params->meal_count_mtx);
	while (i < params->num_of_philosophers)
	{
		if (philos[i].meals_consumed < params->required_meals)
		{
			pthread_mutex_unlock(&params->meal_count_mtx);
			return ;
		}
		i++;
	}
	params->all_finished_eating = true;
	pthread_mutex_unlock(&params->meal_count_mtx);
}

void	monitor_dinner(t_philosopher *philos)
{
	t_dinner_params	*params;

	params = ((t_philosopher *)philos)->shared_data;
	if (params->num_of_philosophers == 1)
		return ;
	while (is_dinner_ongoing(philos))
	{
		if (check_for_death(philos, params))
			break ;
		ft_ms_sleep(1, philos);
		check_if_all_ate(philos, params);
	}
}