/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_release.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:50:35 by galtange          #+#    #+#             */
/*   Updated: 2023/02/16 18:10:27 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ft_resolve_f_fork(t_data *philo)
{
	if (philo->id % 2 == 0)
	{
		return (&philo->forks[philo->id]);
	}
	if (philo->id == philo->arg->size - 1)
	{
		return (&philo->forks[0]);
	}
	return (&philo->forks[philo->id + 1]);
}

pthread_mutex_t	*ft_resolve_s_fork(t_data *philo)
{
	if (philo->id % 2 == 0)
	{
		if (philo->id == philo->arg->size - 1)
		{
			return (&philo->forks[0]);
		}
		return (&philo->forks[philo->id + 1]);
	}
	return (&philo->forks[philo->id]);
}

void	ft_take_forks(t_data *philo, pthread_mutex_t *f, pthread_mutex_t *s)
{
	pthread_mutex_lock(f);
	ft_printstatus(philo, "has taken a fork\n");
	pthread_mutex_lock(s);
	ft_printstatus(philo, "has taken a fork\n");
}

void	ft_put_forks(pthread_mutex_t *f, pthread_mutex_t *s)
{
	pthread_mutex_unlock(f);
	pthread_mutex_unlock(s);
}
