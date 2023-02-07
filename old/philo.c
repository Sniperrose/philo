/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:43:22 by galtange          #+#    #+#             */
/*   Updated: 2023/02/02 20:15:56 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int ft_check_args(char **argv, int size)
{
    if (size <= 0 || size > 200)
        return (ft_msg("N of philos must be 0 < N < 201"));
    if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
        return (ft_msg("Error in args!\n"));
    if (argv[5] && ft_atoi(argv[1]) >= 0)
        return (ft_msg("Error in args!\n"));
    return (1);
}

int	main(int argc, char **argv)
{
	t_data	*philo;

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
	{
		ft_free(philo, philo->size);
		return(0);
	}
	if (!ft_startphilo(philo, philo->size))
		printf("pthread_create err!\n");
	ft_free(philo, philo->size);
	return (0);
}