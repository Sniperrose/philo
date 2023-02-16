/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_to_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:30:48 by galtange          #+#    #+#             */
/*   Updated: 2023/02/16 18:30:50 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_data *philo)
{
	pthread_mutex_lock(&philo->eat);
	if (philo->n_eaten == philo->arg->n_eat)
	{
		pthread_mutex_unlock(&philo->eat);
		return ;
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

void	ft_thinking(t_data *philo)
{
	ft_printstatus(philo, "is thinking\n");
	usleep(100);
}
