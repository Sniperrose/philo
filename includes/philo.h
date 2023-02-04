/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:42:27 by galtange          #+#    #+#             */
/*   Updated: 2023/02/02 19:42:32 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define	PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/syscall.h>
# include <time.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_data
{
    int     size;
    int     id;
    int     r_fork;
    int     l_fork;
    int		t2_die;
	int		t2_eat;
	int		t2_sleep;
    int     *end;
    struct timeval  t_start;
    long int   t_lasteat;
    pthread_t	thread;
    pthread_mutex_t	fork;
    pthread_mutex_t	*control;
}   t_data;

int	ft_atoi(const char *nptr);
int	ft_err_msg(const char *msg);
long	ft_timestamp(struct timeval start);

t_data *ft_initialize(char **argv, t_data *philo);
void	*routine(void *philos);


void free_mutex(t_data	*philo, int	size);
void	free_thread(t_data *philos, int size);


#endif
