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

void	ft_init_args(t_data *philo, char **argv, int size, int *end)
{
	int				i;
	struct timeval	time;

	i = 0;
	gettimeofday(&time, NULL);
	while (i < size)
	{
		philo[i].size = size;
		philo[i].id = i;
		philo[i].l_side = (i + 1) % size;
		philo[i].r_side = i;
		philo[i].t2_die = ft_atoi(argv[2]);
		philo[i].t2_eat = ft_atoi(argv[3]);
		philo[i].t2_sleep = ft_atoi(argv[4]);
		philo[i].n_eat = 0;
		philo[i].t_start = time;
		philo[i].t_last = 0;
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_mutex_init(&philo[i].eat, NULL);
		philo[i].end = end;
		i++;
	}
}

int	ft_initialize(char **argv, t_data *philo)
{
	int	size;
	int	*end;

	size = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_data) * size);
	if (!philo)
		return (0);
	end = malloc (sizeof(int) * 2);
	memset(end, 0, sizeof(int));
	ft_init_args(philo, argv, size, end);
	return (1);
}
