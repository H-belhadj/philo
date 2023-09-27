/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:41:49 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/09/26 22:45:17 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigists(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_validint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!ft_isdigists(str[i]))
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigists(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		r;
	int		sign;

	i = 0;
	r = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	return (r * sign);
}
