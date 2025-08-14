/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:54:52 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/13 21:08:46 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	display_error_msg("gettimeofday");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

time_t	get_elapsed_time(time_t start_time)
{
	return (get_time_ms() - start_time);
}
