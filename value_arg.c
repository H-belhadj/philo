/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:40:27 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/09/26 22:40:38 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*arg_value(t_list **list, int argc, char **argv)
{
	(*list)->number_of_philosophers = ft_atoi(argv[1]);
	(*list)->time_to_die = ft_atoi(argv[2]);
	(*list)->time_to_eat = ft_atoi(argv[3]);
	(*list)->time_to_sleep = ft_atoi(argv[4]);
	(*list)->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		(*list)->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	(*list)->start_time = timer();
	return (*list);
}
