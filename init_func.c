/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:54:03 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/13 21:22:42 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static bool init_dinner_params(t_dinner_params *params, char **args)
{
	memset(params, 0, sizeof(t_dinner_params));
	params->num_of_philosophers = ft_atoi(args[1]);
	params->time_to_expire = ft_atoi(args[2]);
	params->eating_duration = ft_atoi(args[3]);
	params->sleeping_duration = ft_atoi(args[4]);
	if (args[5])
		params->required_meals = ft_atoi(args[5]);
	else
		params->required_meals = -1;
	params->all_finished_eating = false;
	params->a_philosopher_died = false;
	params->start_of_dinner = get_time_ms();
	if (pthread_mutex_init(&params->death_mtx, NULL))
		return (false);
	if (pthread_mutex_init(&params->display_mtx, NULL))
	{
		pthread_mutex_destroy(&params->death_mtx);
		return (false);
	}
	if (pthread_mutex_init(&params->meal_count_mtx, NULL))
	{
		pthread_mutex_destroy(&params->death_mtx);
		pthread_mutex_destroy(&params->display_mtx);
		return (false);
	}
	return (true);
}

static bool init_philosophers(t_dinner_params *params, t_philosopher *philos)
{
	int i;

	i = 0;
	params->utensils = malloc(sizeof(pthread_mutex_t) * params->num_of_philosophers);
	if (!params->utensils)
		return (false);
	while (i < params->num_of_philosophers)
	{
		if (pthread_mutex_init(&params->utensils[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&params->utensils[i]);
			free(params->utensils);
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < params->num_of_philosophers)
	{
		philos[i].philosopher_id = i + 1;
		philos[i].meals_consumed = 0;
		philos[i].left_utensil = i;
		philos[i].right_utensil = (i + 1) % params->num_of_philosophers;
		philos[i].shared_data = params;
		i++;
	}
	return (true);
}

bool    initialize_all_data(t_dinner_params *params, t_philosopher **philos, char **args)
{
	if (!init_dinner_params(params, args))
		return (false);
	*philos = (t_philosopher *)malloc(sizeof(t_philosopher) * params->num_of_philosophers);
	if (!*philos)
	{
		pthread_mutex_destroy(&params->death_mtx);
		pthread_mutex_destroy(&params->display_mtx);
		pthread_mutex_destroy(&params->meal_count_mtx);
		return (false);
	}
	if (!init_philosophers(params, *philos))
	{
		pthread_mutex_destroy(&params->death_mtx);
		pthread_mutex_destroy(&params->display_mtx);
		pthread_mutex_destroy(&params->meal_count_mtx);
		free(*philos);
		return (false);
	}
	return (true);
}