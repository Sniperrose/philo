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
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/syscall.h>
# include <time.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_times
{
	int	die;
	int eat;
	int sleep;
}	t_times;

typedef struct s_data
{
	t_times			*t2;
	int				size;
	int				id;
	int				fork_id_leftside;
	int				fork_id_rightside;
	int				n_eat;
	int				*end;
	long			t_last;
	struct timeval	t_start;
	pthread_t		thread;
	pthread_t		death_check;
	pthread_mutex_t	fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	*control;
	pthread_mutex_t	*msg;
}	t_data;

int	ft_atoi(const char *nptr);
int	ft_msg(const char *msg);
// t_times	*ft_check_get_args(char **argv);
#endif

