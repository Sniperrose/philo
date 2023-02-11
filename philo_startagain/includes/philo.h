/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:42:27 by galtange          #+#    #+#             */
/*   Updated: 2023/02/08 13:43:00 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/syscall.h>
# include <time.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_arg
{
    int	size;
    int die;
	int	eat;
	int	sleep;
    int n_eat;
}   t_arg;


typedef struct s_data
{
	int				id;
	int				r_sidefork_id;
	int				l_sidefork_id;
	int				n_eaten;
	int				*end;
	int			    t_last;
    t_arg           *arg;
	struct timeval	t_start;
	pthread_t		thread;
	pthread_t		death_check;
	pthread_mutex_t	fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*control;
	pthread_mutex_t	*message;
}	t_data;

int ft_getargs(t_arg *arg, char **argv);
int	ft_msg(const char *msg);
int	ft_atoi(const char *nptr);
int ft_init(t_arg *arg, t_data *philo);
int ft_free(t_data *philo);
int ft_startroutine(t_data *philo, int size);
int	ft_timestamp(struct timeval start);
void ft_printstatus(t_data *philo, char *msg);

void ft_ptest(t_data *philo, int size);

#endif