/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:54:09 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/13 21:23:33 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int main(int ac, char **av)
{
	t_dinner_params params;
	t_philosopher   *philos;
	pthread_t       *threads;

	if (!validate_arguments(ac, av) || !validate_values(av))
		return (display_error_msg("Invalid arguments"), 1);
	if (!initialize_all_data(&params, &philos, av))
		return (display_error_msg("Initialization failed"), 1);
	threads = malloc(sizeof(pthread_t) * params.num_of_philosophers);
	if (!threads)
	{
		display_error_msg("Memory allocation failed");
		destroy_all_mutexes(&params);
		free(philos);
		return (1);
	}
	if (!create_philosopher_threads(philos, threads))
	{
		display_error_msg("Thread creation failed");
		destroy_all_mutexes(&params);
		free(philos);
		free(threads);
		return (1);
	}
	monitor_dinner(philos);
	if (!join_philosopher_threads(philos, threads))
	{
		display_error_msg("Thread joining failed");
		destroy_all_mutexes(&params);
		free(philos);
		free(threads);
		return (1);
	}
	destroy_all_mutexes(&params);
	free(philos);
	free(threads);
	return (0);
}