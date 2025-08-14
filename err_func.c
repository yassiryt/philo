/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:53:57 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/14 03:28:06 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_error_msg(char *message)
{
	ft_putstr_fd(2, "\033[31mError:");
	ft_putstr_fd(2, message);
	ft_putstr_fd(2, " \033[0m\n");
}

void	cleanup_resources(t_dinner_params *params,
		t_philosopher **philos, pthread_t **threads)
{
	destroy_all_mutexes(params);
	free(*philos);
	free(*threads);
}
