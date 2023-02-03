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
    int     id;
    int     r_fork;
    int     l_fork;
    int		t2_die;
	int		t2_eat;
	int		t2_sleep;
    int     *end;
    struct timeval	t_begin;
    struct timeval	t_now;
    pthread_t	philo;
    pthread_mutex_t	*forks;
    pthread_mutex_t	*control;
}   t_data;

int	ft_atoi(const char *nptr);
int	ft_err_msg(const char *msg);

int ft_initialize(char **argv, t_data *philo);

int ft_free(t_data *philo);
#endif
