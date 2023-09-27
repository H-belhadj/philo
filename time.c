/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:37:32 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/09/26 22:47:45 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timer(void)
{
	struct timeval		tmp;
	long				time;

	gettimeofday(&tmp, NULL);
	time = tmp.tv_sec * 1000 + tmp.tv_usec / 1000; 
	return (time);
}

long	time_cur(t_philo *philo)
{
	long	time;

	time = timer() - philo->data->start_time;
	return (time);
}
