/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_release.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:50:35 by galtange          #+#    #+#             */
/*   Updated: 2023/02/14 21:41:18 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/philo.h"
#include "philo.h"

void	ft_tookforsk(t_data *ph)
{
	pthread_mutex_lock(&ph->forks[ph->r_sidefork_id]);
	ft_printstatus(ph, "has taken a fork\n");
	pthread_mutex_lock(&ph->forks[ph->l_sidefork_id]);
	ft_printstatus(ph, "has taken a fork\n");
}

void	ft_put_theforks(t_data *philo)
{
	pthread_mutex_unlock(&philo->forks[philo->r_sidefork_id]);
	pthread_mutex_unlock(&philo->forks[philo->l_sidefork_id]);
	usleep(100);
}

void	ft_eat(t_data *philo)
{
	pthread_mutex_lock(&philo->eat);
	ft_printstatus(philo, "is eating\n");
	pthread_mutex_lock(philo->control);
	philo->n_eaten++;
	pthread_mutex_unlock(philo->control);
	philo->t_last = ft_timestamp(philo->t_start);
	pthread_mutex_unlock(&philo->eat);
	usleep(philo->arg->eat * 1000);
//	philo->n_eaten++;
}

void	ft_sleep(t_data *philo)
{
	ft_printstatus(philo, "is sleeping\n");
	usleep(philo->arg->sleep * 1000);
}
