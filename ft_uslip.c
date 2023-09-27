/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uslip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:56:00 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/09/27 17:43:50 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time)
{
	long	at_moment;

	at_moment = timer();
	while (timer() < time + at_moment)
		usleep(500);
}

void	ft_print(char *str, t_philo *philo)
{
	long	time;

	time = time_cur(philo);
	printf("%ld %d %s", time, philo->n_philo, str);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->is_end == 1)
		return ;
	ft_print("is eating\n", philo);
	pthread_mutex_unlock(&philo->data->write);
	pthread_mutex_lock(&philo->data->die);
	philo->last_eat = timer();
	pthread_mutex_unlock(&philo->data->die);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->eat);
	philo->eat++;
	if (philo->eat == philo->data->number_of_times_each_philosopher_must_eat)
		philo->data->finish++;
	pthread_mutex_unlock(&philo->data->eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	*diner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		ft_fork(philo);
		eat(philo);
		pthread_mutex_lock(&philo->data->write);
		if (philo->data->is_end == 1)
			return (NULL);
		ft_print("is sleeping\n", philo);
		pthread_mutex_unlock(&philo->data->write);
		ft_usleep(philo->data->time_to_sleep);
		pthread_mutex_lock(&philo->data->write);
		if (philo->data->is_end == 1)
			return (NULL);
		ft_print("is thinking\n", philo);
		pthread_mutex_unlock(&philo->data->write);
	}
}
