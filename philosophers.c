/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:42:14 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/09/27 18:04:41 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	short_cena(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat);
	if (philo->data->number_of_times_each_philosopher_must_eat > 0 
		&& philo->data->finish >= philo->data->number_of_philosophers)
	{
		philo->data->is_end = 1;
		printf("ALL THE PHILOSOPHERS ARE EAT %d TIME\n",
			philo->data->number_of_times_each_philosopher_must_eat);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->eat);
	return (0);
}

int	sort_cena_2(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die);
	if (timer() - philo->last_eat >= philo->data->time_to_die 
		&& time_cur(philo) % philo->data->time_to_die == 0)
	{
		philo->data->is_end = 1;
		ft_print("died\n", philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->die);
	return (0);
}

void	cena(t_philo *philo)
{
	int	i;

	i = 0;
	while (++i <= philo->data->number_of_philosophers)
	{
		if (pthread_create(&philo->thread, NULL, &diner, philo))
			return ;
		philo = philo->next;
		usleep(50);
	}
	while (1)
	{
		if (short_cena(philo) || sort_cena_2(philo))
			return ;
		philo = philo->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list;
	t_philo	*philo;

	philo = NULL;
	list = malloc(sizeof(t_list));
	if (cheack(argc, argv))
		return (1);
	list = arg_value(&list, argc, argv);
	philo = ft_philo(list);
	if (!philo)
		return (1);
	cena(philo);
	return (0);
}
