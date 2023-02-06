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


void	ft_test(t_data *philo, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("philo[%d], t2_die:%d, t2_eat:%d, t_sleep:%d", 
			philo[i].id, philo[i].t2_die, philo[i].t2_eat, philo[i].t2_sleep);
		printf(" | forks[%d&%d]", philo[i].r_fork, philo[i].l_fork);
		printf(" | end[0]=%d, end[1]=%d\n", philo[i].end[0], philo[i].end[1]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*philo;

	philo = NULL;
	if (argc != 5 && argc != 6)
	{
		printf("Wrong argument umber!\nTIP: number_of_philosophers time_to_die time");
		printf("_to_eat time_to_sleep\n[number_of_times_each_philosopher_must_eat]");
		return (0);
	}
	philo = ft_initialize(argv, philo);
	if (!philo)
		return(ft_err_msg("Err in init!\n"));

	/*free test*/
	free_mutex(philo, philo->size);
	int	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		free(&philo[i]);
		i++;
	}
	free_thread(philo, philo->size);
	free(philo->end);
	free(philo);
	return (0);
}