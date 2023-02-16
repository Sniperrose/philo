/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:42:27 by galtange          #+#    #+#             */
/*   Updated: 2023/02/14 16:45:06 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/syscall.h>
# include <time.h>
# include <sys/time.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_arg
{
	int	size;
	int	die;
	int	eat;
	int	sleep;
	int	n_eat;
}	t_arg;

typedef struct s_data
{
	int				id;
	int				n_eaten;
	int				*end;
	int				t_last;
	t_arg			*arg;
	struct timeval	t_start;
	pthread_t		thread;
	pthread_t		death_check;
	pthread_mutex_t	eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*control;
	pthread_mutex_t	*message;
}	t_data;

int				ft_getargs(t_arg *arg, char **argv);
int				ft_msg(const char *msg);
int				ft_atoi(const char *nptr);
int				ft_init(t_arg *arg, t_data *philo, int size);
int				ft_free(t_data *philo);
int				ft_startroutine(t_data *philo, int size);
void			*ft_ifdied(void *philo);
bool			ft_all_eat(t_data *ph);
bool			ft_check_died(t_data *ph);
void			*routine(void *philo);
void			ft_take_forks(t_data *ph, pthread_mutex_t *f,
					pthread_mutex_t *s);
void			ft_put_forks(pthread_mutex_t *f, pthread_mutex_t *s);
void			ft_eat(t_data *philo);
void			ft_sleep(t_data *philo);
void			ft_thinking(t_data *philo);
pthread_mutex_t	*ft_resolve_f_fork(t_data *philo);
pthread_mutex_t	*ft_resolve_s_fork(t_data *philo);
void			ft_put_theforks(t_data *ph);
int				ft_timestamp(struct timeval start);
void			ft_printstatus(t_data *philo, char *msg);
#endif
