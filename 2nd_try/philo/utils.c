/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:34:17 by galtange          #+#    #+#             */
/*   Updated: 2023/02/12 18:35:36 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] > 7 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (47 < nptr[i] && nptr[i] < 58)
	{
		num = 10 * num + (nptr[i] - '0');
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
		i++;
	}
	return (num * sign);
}

int	ft_msg(const char *msg)
{
	if (msg)
	{
		printf("%s", msg);
	}
	return (0);
}

int	ft_timestamp(struct timeval start)
{
	long			ms;
	struct timeval	end;

	gettimeofday(&end, NULL);
	ms = (((end.tv_sec * 1000) + (end.tv_usec / 1000))
			- ((start.tv_sec * 1000) + (start.tv_usec / 1000)));
	return (ms);
}

void	ft_printstatus(t_data *philo, char *msg)
{
	pthread_mutex_lock(philo->message);
	pthread_mutex_lock(philo->control);
	if (philo->end[0] || philo->end[1])
	{
		pthread_mutex_unlock(philo->control);
		pthread_mutex_unlock(philo->message);
		return ;
	}
	printf("%d ", ft_timestamp(philo->t_start));
	printf("%d ", philo->id + 1);
	printf("%s", msg);
	pthread_mutex_unlock(philo->control);
	pthread_mutex_unlock(philo->message);
}
