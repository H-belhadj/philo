/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:42:23 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/09/27 15:59:28 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_list {
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	long				start_time;
	int					is_end;
	int					finish;
	pthread_mutex_t		write;
	pthread_mutex_t		eat;
	pthread_mutex_t		die;
}t_list;

typedef struct s_philo{
	int				is_dead;
	int				n_philo;
	t_list			*data;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_t		thread;
	pthread_mutex_t	fork;
	long			last_eat;
	int				eat;
}t_philo;

int		cheack(int ac, char **av);
t_list	*arg_value(t_list **list, int argc, char **argv);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_validint(char *str);
void	ft_putchar(char c);
int		write_error(char *str);
void	ft_putstr(char *str);
t_philo	*ft_philo(t_list *list);
void	ft_fork(t_philo *philo);
long	timer(void);
long	time_cur(t_philo *philo);
void	ft_print(char *str, t_philo *philo);
void	ft_usleep(long time);
void	ft_print(char *str, t_philo *philo);
void	eat(t_philo *philo);
void	*diner(void *arg);

#endif
