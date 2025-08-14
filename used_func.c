/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:54:58 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/13 21:03:52 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dinner_ongoing(t_philosopher *p)
{
	pthread_mutex_lock(&p->shared_data->death_mtx);
	pthread_mutex_lock(&p->shared_data->meal_count_mtx);
	if (p->shared_data->a_philosopher_died
		|| p->shared_data->all_finished_eating)
	{
		pthread_mutex_unlock(&p->shared_data->meal_count_mtx);
		pthread_mutex_unlock(&p->shared_data->death_mtx);
		return (false);
	}
	pthread_mutex_unlock(&p->shared_data->meal_count_mtx);
	pthread_mutex_unlock(&p->shared_data->death_mtx);
	return (true);
}

void	ft_ms_sleep(time_t ms, t_philosopher *p)
{
	time_t	start;

	if (!is_dinner_ongoing(p))
		return ;
	start = get_time_ms();
	while (get_elapsed_time(start) < ms)
	{
		usleep(250);
		if (!is_dinner_ongoing(p))
			break ;
	}
}

void	destroy_all_mutexes(t_dinner_params *d)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&d->death_mtx);
	pthread_mutex_destroy(&d->display_mtx);
	pthread_mutex_destroy(&d->meal_count_mtx);
	while (i < d->num_of_philosophers)
	{
		pthread_mutex_destroy(&d->utensils[i]);
		i++;
	}
	free(d->utensils);
}