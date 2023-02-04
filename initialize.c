#include "includes/philo.h"

void     ft_init_args(t_data *philo, char **argv, int size, int *end)
{
    int i;

    i = 0;
    if (argv[5])
        end[1] = ft_atoi(argv[5]);
    else
        end[1] = -1;
    while (i < size)
    {
        philo[i].size = size;
        philo[i].t2_die = ft_atoi(argv[2]);
        philo[i].t2_eat = ft_atoi(argv[3]);
        philo[i].t2_sleep = ft_atoi(argv[4]);
        philo[i].id = i;
        philo[i].l_fork = (i + 1) % size;
        philo[i].r_fork = i;
        philo[i].end = end;
        i++;
    }
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
        // if (pthread_join(philo[i].thread, NULL) != 0)
		// {
		// 	return (ft_err_msg("Error in pthread_join!\n"));
		// }
		usleep(100);
		i++;
	}
    return (0);
}

int ft_init_mutex(t_data *philo, int size)
{
    int i;

    i = 0;
    while(i < size)
	{
		if (pthread_mutex_init(&philo[i].forks, NULL) != 0)
		{
			return (ft_err_msg("Mutex_init error!\n"));
		}
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
    ft_init_args(philo, argv, size, end);
    if (ft_init_mutex(philo, size) != 0)
        return (NULL);
    if (ft_init_threads(philo, size) != 0)
        return (NULL);
    return (philo);
}