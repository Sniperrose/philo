/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:54:58 by galtange          #+#    #+#             */
/*   Updated: 2023/02/14 21:45:24 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/philo.h"
#include "philo.h"

void	*ft_eat_alone(t_data *ph)
{
	pthread_mutex_lock(&ph->forks[ph->r_sidefork_id]);
	ft_printstatus(ph, "has taken a fork\n");
	usleep (ph->arg->die * 1000);
	pthread_mutex_unlock(&ph->forks[ph->r_sidefork_id]);
	return (NULL);
}

void	*routine(void *philo)
{
	t_data	*ph;

	ph = (t_data *)philo;
	if (ph->arg->size == 1)
	{
		return (ft_eat_alone(ph));
	}
	if ((ph->id % 2) != 0)
	{
		usleep(15000);
	}
	while (1)
	{
		if (ph->end[0] == 1 || ph->end[1] == 1 || ph->n_eaten == ph->arg->n_eat)
			break ;
		if (pthread_mutex_lock(&ph->forks[ph->r_sidefork_id]) == 0)
			ft_printstatus(ph, "has taken a fork\n");
		usleep(100);
		if (pthread_mutex_lock(&ph->forks[ph->l_sidefork_id]) == 0)
			ft_printstatus(ph, "has taken a fork\n");
		// ft_tookforsk(ph);
		ft_eat(ph);
		ft_put_theforks(ph);
		ft_sleep(ph);
		ft_printstatus(philo, "is thinking\n");
	}
	return (NULL);
}

bool	ft_check_died(t_data *ph)
{
	int	i;
	int	size;
	int	diff;

	size = ph->arg->size;
	i = 0;
	diff = 0;
	while (i < size)
	{
		pthread_mutex_lock(&ph[i].eat);
		diff = ph[i].t_last;
		pthread_mutex_unlock(&ph[i].eat);
		if ((ft_timestamp(ph->t_start) - diff) > ph->arg->die)
		{
			ft_printstatus(&ph[i], "died\n");
			pthread_mutex_lock(ph->control);
			ph->end[0] = 1;
			pthread_mutex_unlock(ph->control);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	ft_all_eat(t_data *ph)
{
	int	i;
	int	size;

	size = ph->arg->size;
	i = 0;
	while (size-- >= 0)
	{
		pthread_mutex_lock(ph->control);
		int	eten = ph[i].n_eaten;
		pthread_mutex_unlock(ph->control);
		if (eten == ph->arg->n_eat)
			i++;
	}
	if (i == size)
	{
		pthread_mutex_lock(ph->control);
		ph->end[1] = 1;
		pthread_mutex_unlock(ph->control);
		return (true);
	}
	return (false);
}

void	*ft_ifdied(void *philo)
{
	t_data	*ph;

	ph = (t_data *)philo;
	while (1)
	{
		if (!ft_check_died(ph))
		{
			break ;
		}
		if (ft_all_eat(ph))
		{
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}
