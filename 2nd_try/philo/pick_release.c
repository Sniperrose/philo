/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_release.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:50:35 by galtange          #+#    #+#             */
/*   Updated: 2023/02/12 19:51:33 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_tookforsk(t_data *ph)
// {
// 	pthread_mutex_lock(&ph->forks[ph->r_sidefork_id]);
// 	pthread_mutex_lock(ph->control);
// 	if (ph->eat_later == 1)
// 	{
// 		usleep(1000);
// 		ph->eat_later = 0;
// 	}
// 	pthread_mutex_unlock(ph->control);
// 	pthread_mutex_lock(&ph->forks[ph->l_sidefork_id]);
// 	ft_printstatus(ph, "has taken a fork\n");
// }

int	ft_check_fork(pthread_mutex_t fork)
{
	if (pthread_mutex_lock(&fork) != 0)
	{
		// pthread_mutex_unlock(&fork);
		return (0);
	}
	pthread_mutex_unlock(&fork);
	return (1);
}

void	ft_tookforsk_1st(t_data *ph)
{
	pthread_mutex_lock(&ph->forks[ph->r_sidefork_id]);
	ft_printstatus(ph, "has taken a fork\n");
}

void	ft_tookforsk_2nd(t_data *ph)
{
	pthread_mutex_lock(&ph->forks[ph->l_sidefork_id]);
	ft_printstatus(ph, "has taken a fork\n");
}

void ft_resolve_1st_fork(t_data *ph)
{
	if (ph->id % 2 == 0)
		ft_tookforsk_1st(ph);
}

void ft_resolve_2nd_fork(t_data *ph)
{
	if (ph->id % 2 == 0)
		ft_tookforsk_2nd(ph);
}

void	ft_put_theforks(t_data *philo)
{
	pthread_mutex_unlock(&philo->forks[philo->r_sidefork_id]);
	pthread_mutex_unlock(&philo->forks[philo->l_sidefork_id]);
	// pthread_mutex_lock(philo->control);
	// philo->eat_later = 1;
	// pthread_mutex_unlock(philo->control);
}

void	ft_eat(t_data *philo)
{
	pthread_mutex_lock(&philo->eat);
	if (philo->n_eaten == philo->arg->n_eat)
	{
		pthread_mutex_unlock(&philo->eat);
		return;		
	}
	philo->n_eaten++;
	ft_printstatus(philo, "is eating\n");
	philo->t_last = ft_timestamp(philo->t_start);
	pthread_mutex_unlock(&philo->eat);
	usleep(philo->arg->eat * 1000);
}

void	ft_sleep(t_data *philo)
{
	ft_printstatus(philo, "is sleeping\n");
	usleep(philo->arg->sleep * 1000);
}
