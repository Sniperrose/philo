#include "includes/philo.h"

void     ft_init_philos(t_data *philo, char **argv, int size, int *end)
{
    int i;
    struct timeval time;
    
    i = 0;
    gettimeofday(&time, NULL);
    while (i < size)
    {
        philo[i].size = size;
        philo[i].t2_die = ft_atoi(argv[2]);
        philo[i].t2_eat = ft_atoi(argv[3]);
        philo[i].t2_sleep = ft_atoi(argv[4]);
        philo[i].n_eat = 0;
        philo[i].id = i;
        philo[i].l_fork = (i + 1) % size;
        philo[i].r_fork = i;
        philo[i].t_start = time;
        philo[i].end = end;
        i++;
    }
}

int ft_init_mutex(t_data *philo, int size)
{
    int i;
    pthread_mutex_t	ctrl;
    pthread_mutex_t msg;

    pthread_mutex_init(&ctrl, NULL);
    pthread_mutex_init(&msg, NULL);
    while (i < size)
    {
        if(pthread_mutex_init(&philo[i].fork, NULL) != 0)
            return (ft_msg("Mutex_init!\n"));
        if(pthread_mutex_init(&philo[i].eat, NULL) != 0)
            return (ft_msg("Mutex_init!\n"));
        philo[i].control = &ctrl;
        philo[i].msg = &msg;
        i++;
    }
    return (1);
}

t_data  *ft_initialize(char **argv, t_data *philo)
{
    int size;
    int *end;

    size = ft_atoi(argv[1]);
    philo = malloc(sizeof(t_data) * size);
    if (!philo)
        return (NULL);
    end = (int *)malloc(sizeof(int) * 2);
    if (!end)
        return (NULL);
    philo = memset(philo, 0, size);
    end = memset(end, 0, 1);
    if (argv[5])
        end[1] = ft_atoi(argv[5]);
    if(!ft_init_mutex(philo, size))
        return (NULL);
    ft_init_philos(philo, argv, size, end);
    return (philo);
}
