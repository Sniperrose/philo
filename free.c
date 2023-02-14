/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:45:20 by galtange          #+#    #+#             */
/*   Updated: 2023/02/08 13:48:37 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	ft_free(t_data *philo, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&philo[i].fork);
		pthread_mutex_destroy(&philo[i].eat);
		i++;
	}
	pthread_mutex_destroy(philo->control);
	pthread_mutex_destroy(philo->msg);
	free(philo->end);
	free(philo);
	return (0);
}
