/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:29:07 by yatanagh          #+#    #+#             */
/*   Updated: 2025/07/27 03:51:13 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *s)
{
	int i;
	long rs;

	i = 0;
	rs = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (rs >= 9223372036854775807)
			return (-1);
		rs *= 10;
		rs += s[i] - 48;
		i++;
	}
	return (rs);
}
long long	gt_ms(void)
{
	struct timeval	cur;
	gettimeofday(&cur, NULL);
	return (cur.tv_sec * 1000);
}
void	print_status(t_philosopher *philo, const char *message)
{
	printf("%ld %s", gt_ms(), message);
}
