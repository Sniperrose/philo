/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:07:42 by galtange          #+#    #+#             */
/*   Updated: 2023/02/14 21:24:10 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/philo.h"
#include "philo.h"

int	ft_free(t_data *philo)
{
	int	i;
	int	size;

	i = 0;
	size = philo->arg->size;
	while (i < size)
	{
		pthread_mutex_destroy(&philo[i].eat);
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(philo->message);
	pthread_mutex_destroy(philo->control);
	if (philo->forks)
		free(philo->forks);
	if (philo->message)
		free(philo->message);
	if (philo->control)
		free(philo->control);
	if (philo->end)
		free(philo->end);
	if (philo)
		free(philo);
	return (0);
}
