#include "includes/philo.h"

void     ft_init_args(t_data *philo, char **argv, int size, int *end)
{
    int i;
    struct timeval time;
    
    i = 0;
    if (argv[5])
        end[1] = ft_atoi(argv[5]);
    else
        end[1] = -1;
    gettimeofday(&time, NULL);
    while (i < size)
    {
        philo[i].size = size;
        philo[i].t2_die = ft_atoi(argv[2]);
        philo[i].t2_eat = ft_atoi(argv[3]);
        philo[i].t2_sleep = ft_atoi(argv[4]);
        philo[i].id = i;
        philo[i].l_fork = (i + 1) % size;
        philo[i].r_fork = i;
        philo[i].t_start = time;
        philo[i].end = end;
        philo[i].fork = philo->fork;
        philo[i].control = philo->control;
        i++;
    }
}

int ft_init_mutex(t_data *philo, int size)
{
    int i;

    philo->fork = malloc(sizeof(pthread_mutex_t) * size);
    if (!philo->fork)
        return (1);
    i = 0;
    while(i < size)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL) != 0)
			return (ft_err_msg("Mutex_init error!\n"));
		i++;
	}
    philo->control = malloc(sizeof(pthread_mutex_t) * 1);
    if (!philo->control)
        return (1);
    pthread_mutex_init(philo->control, NULL);
    return (0);
}

int ft_init_threads(t_data *philo, int size)
{
    int i;

    i = 0;
    while(i < size)
	{
		if (pthread_create(&(philo[i].thread), NULL, routine, &philo[i]) != 0)
		{
			return (ft_err_msg("Error in pthread_create!\n"));
		}
		usleep(50);
		i++;
	}
    i = 0;
    while(i < size)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }
    return (0);
}

t_data  *ft_initialize(char **argv, t_data *philo)
{
    int size;
    int *end;

    size = ft_atoi(argv[1]);
    if(size <= 0 || size > 200 || (argv[5] && ft_atoi(argv[5]) <= 0))
        return (NULL);
    philo = malloc(sizeof(t_data) * size);
    if (!philo)
        return (NULL);
    philo = memset(philo, 0, size);
    end = malloc(sizeof(int) * 2);
    if (!end)
        return (NULL);
    end = memset(end, 0, 2);
    if (ft_init_mutex(philo, size) != 0)
        return (NULL);
    ft_init_args(philo, argv, size, end);
    if (ft_init_threads(philo, size) != 0)
        return (NULL);
    return (philo);
}