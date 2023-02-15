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

#include "includes/philo.h"

void	ft_try_took_rside(t_data *ph)
{
	if (ph->t_last > ph[ph->id - 1].t_last)
	{
		usleep((ph->arg->eat * 0.25) * 10000);
	}
	pthread_mutex_lock(&ph->forks[ph->r_sidefork_id]);
	// printf("fork id = %d\n",ph->r_sidefork_id);
	ft_printstatus(ph, "took a fork\n");
}

void	ft_try_took_lside(t_data *ph)
{
	// printf("[%d]last = %d && [%d]last+i = %d\n",ph->id, ph->t_last, ph->l_sidefork_id, ph[ph->l_sidefork_id].t_last);
	if (ph->t_last > ph[ph->l_sidefork_id].t_last)
	{
		usleep((ph->arg->eat * 0.25) * 1000);
	}
	pthread_mutex_lock(&ph->forks[ph->l_sidefork_id]);
	// printf("%d took %d\n", ph->id, ph->l_sidefork_id);
	ft_printstatus(ph, "took a fork\n");
	// ft_printstatus(ph, "took a fork\n");
}

void	ft_put_theforks(t_data *philo)
{
	pthread_mutex_unlock(&philo->forks[philo->r_sidefork_id]);
	pthread_mutex_unlock(&philo->forks[philo->l_sidefork_id]);
}
