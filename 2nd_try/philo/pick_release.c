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
