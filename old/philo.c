/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:43:22 by galtange          #+#    #+#             */
/*   Updated: 2023/02/08 13:12:14 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_data			*philo;

	philo = NULL;
	if (argc != 5 && argc != 6)
	{
		printf("TIP: number_of_philosophers time_to_die time");
		printf("_to_eat time_to_sleep\n[number_of_times_must_eat]");
		return (0);
	}
	if (!ft_check_args(argv, ft_atoi(argv[1])))
		return (0);
	philo = ft_initialize(argv, philo);
	if (!philo)
		return (ft_free(philo, philo->size));
	if (!ft_startphilo(philo, philo->size))
	{
		printf("pthread_create err!\n");
		ft_free(philo, philo->size);
	}
	// printf("pthread_create err!\n");
	ft_free(philo, philo->size);
	return (0);
}
