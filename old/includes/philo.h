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

typedef struct s_data
{
	int				size;
	int				id;
	int				r_fork;
	int				l_fork;
	int				t2_die;
	int				t2_eat;
	int				t2_sleep;
	int				n_eat;
	int				*end;
	int				t_last;
	struct timeval	t_start;
	struct timeval	t_lasteat;
	pthread_t		thread;
	pthread_t		death_check;
	pthread_mutex_t	fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	*control;
	pthread_mutex_t	*msg;
}	t_data;

int		ft_check_args(char **argv, int size);
int		ft_atoi(const char *nptr);
int		ft_msg(const char *msg);
int		ft_timestamp(struct timeval start);
void	ft_printstat(t_data *philo, char *str);
void	ft_print(t_data *philo, char *str);
t_data	*ft_initialize(char **argv, t_data *philo);
void	*routine(void *philos);
int		ft_startphilo(t_data *philo, int size);
int		ft_free(t_data *philo, int size);

#endif
