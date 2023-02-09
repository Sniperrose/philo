/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:23:29 by galtange          #+#    #+#             */
/*   Updated: 2023/02/08 13:27:24 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	ft_check_args(char **argv, int size)
{
	if (size <= 0 || size > 200)
		return (ft_msg("N of philos must be 0 < N < 201\n"));
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (ft_msg("Error in args!\n"));
	if (argv[5] && ft_atoi(argv[5]) <= 0)
		return (ft_msg("Error in args!\n"));
	return (1);
}

// int	ft_init_mutex(t_data *philo)
// {
// 	pthread_mutex_t	*ctrl;
// 	pthread_mutex_t	*msg;
// 	int	i;

// 	ctrl = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
// 	msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
// 	if (!ctrl || !msg)
// 		return (0);
// 	pthread_mutex_init(ctrl, NULL);
// 	pthread_mutex_init(msg, NULL);
// 	i = 0;
// 	while (i < philo->size)
// 	{
// 		philo[i].msg = msg;
// 		philo[i].control = ctrl;
// 		i++;
// 	}
// 	return (1);
// }

void	ft_init_philos(t_data *philo, char **argv, int size, int *end)
{
	int				i;
	struct timeval	time;
	pthread_mutex_t	*ctrl;
	pthread_mutex_t	*msg;

	(void) end;
	i = 0;
	gettimeofday(&time, NULL);
	ctrl = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!ctrl || !msg)
		return ;
	pthread_mutex_init(ctrl, NULL);
	pthread_mutex_init(msg, NULL);
	while (i < size)
	{
		philo[i].size = size;
		philo[i].id = i;
		philo[i].l_fork = (i + 1) % size;
		philo[i].r_fork = i;
		philo[i].t2_die = ft_atoi(argv[2]);
		philo[i].t2_eat = ft_atoi(argv[3]);
		philo[i].t2_sleep = ft_atoi(argv[4]);
		philo[i].n_eat = 0;
		philo[i].t_start = time;
		philo[i].t_last = 0;
		memset(&philo[i].t_lasteat, 0, sizeof(struct timeval));
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_mutex_init(&philo[i].eat, NULL);
		philo[i].msg = msg;
		philo[i].control = ctrl;
		philo[i].end = end;
		i++;
	}
}

t_data	*ft_initialize(char **argv, t_data *philo)
{
	int	size;
	int	*end;

	if (!ft_check_args(argv, ft_atoi(argv[1])))
		return (NULL);
	size = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_data) * size);
	if (!philo)
		return (NULL);
	// memset(philo, 0, size * sizeof(t_data));
	end = malloc(sizeof(int) * 2);
	if (!end)
		return (NULL);
	memset(end, -1, 2 * sizeof(int));
	if (argv[5])
		end[1] = ft_atoi(argv[5]);
	// if (!ft_init_mutex(philo))
	// 	return (NULL);
	ft_init_philos(philo, argv, size, end);
	return (philo);
}
