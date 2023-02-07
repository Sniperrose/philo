#include "includes/philo.h"

void	*routine(void *philos)
{
    t_data  *philo;

    philo = (t_data *) philos;

    if ((philo->id % 2) != 0)
        usleep(100);
    while (/* condition */)
    {
        /* code */
    }

    return NULL;
}



int ft_startphilo(t_data *philo, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (pthread_create(&philo[i].thread, NULL, routine, NULL) != 0)
            return (0);
        usleep(100);
        i++;
    }
    i = 0;
    while(i < size)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (0);
        i++;
    }
}