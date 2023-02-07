#include "includes/philo.h"

void	*routine(void *philos)
{
    t_data  *philo;

    philo = (t_data *) philos;

    if ((philo->id % 2) != 0)
        usleep(100);
    if (ft_lockfork(philo))
    {
        ft_eat(philo);
        ft_sleep(philo);
    }
    ft_think(philo);
    return NULL;
}



int ft_startphilo(t_data *philos, int size)
{
    int i;

    i = 0;
    while (i < size)
    {

    }
}