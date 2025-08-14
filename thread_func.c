/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:54:46 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/14 04:29:14 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_philosopher_threads(t_philosopher *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	philos->shared_data->start_of_dinner = get_time_ms();
	while (i < philos->shared_data->num_of_philosophers)
	{
		philos[i].last_meal_timestamp = philos->shared_data->start_of_dinner;
		if (pthread_create(&threads[i], NULL, philo_cycle, &philos[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	join_philosopher_threads(t_philosopher *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < philos->shared_data->num_of_philosophers)
	{
		if (pthread_join(threads[i], NULL))
			return (false);
		i++;
	}
	return (true);
}
