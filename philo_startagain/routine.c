/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:54:58 by galtange          #+#    #+#             */
/*   Updated: 2023/02/12 20:00:33 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_eat(t_data *philo)
{
	pthread_mutex_lock(&philo->eat);
	ft_printstatus(philo, "is eating\n");
	usleep(philo->arg->eat * 1000);
	philo->t_last = ft_timestamp(philo->t_start);
	philo->n_eaten++;
	pthread_mutex_unlock(&philo->eat);
}

void	ft_sleep(t_data *philo)
{
	ft_printstatus(philo, "is sleeping\n");
	usleep(philo->arg->sleep * 1000);
}

void	ft_think(t_data *philo)
{
	ft_printstatus(philo, "is thinking\n");
}

void	*routine(void *philo)
{
	t_data	*ph;

	ph = (t_data *) philo;
	if ((ph->id % 2) != 0)
	{
		usleep((ph->arg->eat * 0.25) * 10000);
	}
	while (1)
	{
		if (ph->n_eaten == ph->arg->n_eat || ph->end[0] || ph->end[1])
			break;
		ft_try_took_rside(ph);
		if (ph->arg->size == 1)
			return (NULL);
		ft_try_took_lside(ph);
		ft_eat(ph);
		ft_sleep(ph);
		ft_put_theforks(ph);
		ft_think(ph);
	}
	return (NULL);
}

void	*ft_ifdied(void *philo)
{
    t_data  *ph;
    int i;

    i = 0;
    ph = (t_data *) philo;
    while (!ph->end[0])
    {
        while(i < ph->arg->size)
	    {
		    if ((ft_timestamp(ph[i].t_start) - ph[i].t_last) > ph->arg->die)
		    {
                ph->end[0] = 1;
                break;
		    }
		    i++;
	    }
        ft_printstatus(&ph[i], "died!\n");
        usleep(10000);
    }
    return (NULL);
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
	i = 0;
	while (i < size)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (ft_msg("pthread_join err!\n"));
		usleep(100);
		i++;
	}
    if (pthread_create(&philo->death_check, NULL, ft_ifdied, philo) != 0)
     return (ft_msg("pthread_create err!\n"));
	if (pthread_join(philo->death_check, NULL) != 0)
			return (ft_msg("pthread_join err!\n"));
	return (1);
}

// printf("+++++im here!!!!\n");
// ft_printstatus(ph, "ft_printstatus test\n");
// printf("----end[0]=%d----\n", ph->end[0]);
// printf("----%d\tn_eaten = %d\tl_eat = %d----\n", 
// ph->id, ph->n_eaten, ph->t_last);
// printf("%dth thread_create, routine test!\n", ph->id);
// test_print(ph);
// printf("----+----\n");
// printf("----end[0]=%d----\n", ph->end[0]);
// void    test_print(t_data *philo)
// {
//     if (pthread_mutex_lock(philo->control) == 0)
//         printf("mutex lock succ!\n");
//     printf("id: %d\n", philo->id);
//     // ft_printtest(philo->arg);
//     printf("forks:\t%d&%d\n", philo->r_sidefork_id, 
// philo->l_sidefork_id);
//     // printf("n_eaten: %d, t_last: %ld\n", 
// philo->n_eaten, philo->t_start.tv_usec);
//     // if (pthread_mutex_unlock(philo->control) == 0)
//     if (pthread_mutex_unlock(philo->control) == 0)
//         printf("mutex unlock succ!\n\n");
// }
