/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:16:18 by galtange          #+#    #+#             */
/*   Updated: 2023/02/12 19:21:33 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	str_isnumbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || 57 < str[i])
			return (0);
		i++;
	}
	return (i);
}

int	ft_getargs(t_arg *arg, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!str_isnumbers(argv[i]))
			return (ft_msg("Error in args!\n"));
		i++;
	}
	arg->size = ft_atoi(argv[1]);
	if (arg->size <= 0 || arg->size > 200)
		return (ft_msg("Number of philos must be 0 < N < 201\n"));
	arg->die = ft_atoi(argv[2]);
	arg->eat = ft_atoi(argv[3]);
	arg->sleep = ft_atoi(argv[4]);
	if (arg->die <= 0 || arg->eat <= 0 || arg->sleep <= 0)
		return (ft_msg("Error in args!\n"));
	if (argv[5] && ft_atoi(argv[5]) <= 0)
		return (ft_msg("Error in args!\n"));
	else if (!argv[5])
		arg->n_eat = -1;
	else
		arg->n_eat = ft_atoi(argv[5]);
	return (1);
}

int	ft_startroutine(t_data *philo, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]) != 0)
			return (ft_msg("pthread_create err!\n"));
		usleep(100);
		i++;
	}
	if (pthread_create(&philo->death_check, NULL, ft_ifdied, philo) != 0)
		return (ft_msg("pthread_create err!\n"));
	i = 0;
	while (i < size)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (ft_msg("pthread_join err!\n"));
		usleep(100);
		i++;
	}
	if (pthread_join(philo->death_check, NULL) != 0)
		return (ft_msg("pthread_join err!\n"));
	return (1);
}

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_data	*philo;

	if (argc != 5 && argc != 6)
	{
		printf("TIP: number_of_philosophers time_to_die time");
		printf("_to_eat time_to_sleep [number_of_times_must_eat]\n");
		return (0);
	}
	if (!ft_getargs(&arg, argv))
		return (0);
	philo = malloc(sizeof(t_data) * arg.size);
	if (!philo)
		return (ft_msg("Err in malloc philo!\n"));
	if (!ft_init(&arg, philo, arg.size))
		return (ft_free(philo));
	if (!ft_startroutine(philo, arg.size))
		return (ft_free(philo));
	ft_free(philo);
	return (0);
}
