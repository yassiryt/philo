/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:54:24 by yatanagh          #+#    #+#             */
/*   Updated: 2025/08/13 21:05:26 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	validate_arguments(int count, char **args)
{
	int	i;
	int	j;

	i = 1;
	if (count < 5 || count > 6)
		return (false);
	while (args[i])
	{
		j = 0;
		while (args[i][j] && is_space(args[i][j]))
			j++;
		if (args[i][j] && args[i][j] == '+')
			j++;
		while (args[i][j] && is_digit(args[i][j]))
			j++;
		while (args[i][j] && is_space(args[i][j]))
			j++;
		if (args[i][j] != '\0')
			return (false);
		i++;
	}
	return (true);
}

bool	validate_values(char **args)
{
	int	i;

	(void)args;
	if (ft_atoi(args[1]) <= 0 || ft_atoi(args[1]) > MAX_PHILOSOPHERS)
		return (false);
	i = 2;
	while (args[i])
	{
		if ((ft_atoi(args[i]) < MIN_TIME && i < 5)
			|| ft_atoi(args[i]) <= 0
			|| ft_atoi(args[i]) > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}