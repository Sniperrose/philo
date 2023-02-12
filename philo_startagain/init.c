/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:36:21 by galtange          #+#    #+#             */
/*   Updated: 2023/02/12 18:51:50 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	ft_init_mutex(t_data *philo, int size)
{
	int				i;
	pthread_mutex_t	*ctrl;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*tmp;

	ctrl = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	tmp = malloc(sizeof(pthread_mutex_t) * size);
	if (!ctrl || !msg || !tmp)
		return (ft_msg("mutex_init err!\n"));
	pthread_mutex_init(ctrl, NULL);
	pthread_mutex_init(msg, NULL);
	i = 0;
	while (i < size)
		pthread_mutex_init(&tmp[i++], NULL);
	i = 0;
	while (i < size)
	{
		philo[i].forks = tmp;
		philo[i].control = ctrl;
		philo[i].message = msg;
		i++;
	}
	return (1);
}

int	ft_init(t_arg *arg, t_data *philo, int size)
{
	int				i;
	struct timeval	time;
	int				*end;

	gettimeofday(&time, NULL);
	end = malloc(sizeof(int) * 2);
	if (!end)
		return (0);
	memset(end, 0, sizeof(int) * 2);
	i = 0;
	while (i < size)
	{
		philo[i].id = i;
		philo[i].arg = arg;
		philo[i].r_sidefork_id = i;
		philo[i].l_sidefork_id = (i + 1) % size;
		philo[i].n_eaten = 0;
		philo[i].t_last = 0;
		philo[i].t_start = time;
		philo[i].end = end;
		pthread_mutex_init(&philo[i].eat, NULL);
		i++;
	}
	return (ft_init_mutex(philo, size));
}

// int	ft_init_mutex(t_data *philo, int size)
// {
// 	int		i;
// 	pthread_mutex_t	*ctrl;
// 	pthread_mutex_t *msg;
// 	pthread_mutex_t *tmp;

// 	ctrl = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
// 	msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
// 	tmp = malloc(sizeof(pthread_mutex_t) * size);

// 	if (!ctrl || !msg || !tmp)
// 		return (ft_msg("mutex_init err!\n"));
// 	if (pthread_mutex_init(ctrl, NULL) != 0)
// 		return (ft_msg("mutex_init err!\n"));
// 	if (pthread_mutex_init(msg, NULL) != 0)
// 		return (ft_msg("mutex_init err!\n"));
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (pthread_mutex_init(&tmp[i], NULL) != 0)
// 			return (ft_msg("tmp mutex_init err!\n"));
// 		i++;
// 	}
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (pthread_mutex_init(&philo[i].eat, NULL) != 0)
// 			return (ft_msg("mutex_init err!\n"));
// 		philo[i].forks = tmp;
// 		philo[i].control = ctrl;
// 		philo[i].message = msg;
// 		i++;
// 	}
// 	return (1);
// }