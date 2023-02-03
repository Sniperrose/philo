#include "includes/philo.h"

void     ft_initphilos(t_data *philo, int size, int *end)
{
    int i;

    i = 0;
    while (i < size)
    {
        philo[i].size = size;
        philo[i].id = i;
        philo[i].l_fork = (i + 1) % size;
        philo[i].r_fork = i;
        philo[i].end = end;
        i++;
    }
}

t_data  *ft_initialize(char **argv, t_data *philo)
{
    int size;
    int *end;

    size = ft_atoi(argv[1]);
    if(size <= 0 || size > 200)
        return (NULL);
    philo = malloc(sizeof(t_data) * size);
    if (!philo)
        return (NULL);
    philo = memset(philo, 0, size);
    end = malloc(sizeof(int) * 2);
    if (!end)
        return (NULL);
    end = memset(end, 0, 2);
    if (argv[5] && (ft_atoi(argv[5]) > 0))
        end[1] = ft_atoi(argv[5]);
    else
        end[1] = -1;
    ft_initphilos(philo, size, end);
    return (philo);
}