/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 06:25:09 by yatanagh          #+#    #+#             */
/*   Updated: 2025/07/27 03:44:36 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_config
{
	int	num_philo;
	long long	td;
	long long	te;
	long long	ts;
	int		ntme;
	long long	st;
}	t_config;

typedef struct s_philosopher
{
	int	num_philo;
	long long	td;
	long long	te;
	long long	ts;
	int		ntme;
	long long	st;
}	t_philosopher;

long		ft_atol(const char *s);
long long	gt_ms(void);

#endif
