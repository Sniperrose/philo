#include "includes/philo.h"

void ft_takefork_r(t_data *philo)
{
    pthread_mutex_lock(&philo[philo->r_fork].fork);
    ft_printstat(philo, "took a fork\n");
}
void ft_putfork_r(t_data *philo)
{
    pthread_mutex_unlock(&philo[philo->r_fork].fork);
    ft_printstat(philo, "put a fork\n");
}

void ft_eat(t_data *philo)
{
    pthread_mutex_lock(&philo->eat);
    ft_printstat(philo, "start eating ...\n");
    usleep(philo->t2_eat * 1000);
    philo->t_last = ft_timestamp(philo->t_start);
    pthread_mutex_unlock(&philo->eat);
    philo[philo->id].n_eat++;
}

void ft_sleep(t_data *philo)
{
    ft_printstat(philo, "sleep!\n");
    usleep(philo->t2_sleep * 1000);
}

void ft_think(t_data *philo)
{
    ft_printstat(philo, "thinking...\n");
}

void *routine(void *philos)
{
    t_data *philo;

    philo = (t_data *)philos;

    if ((philo->id % 2) != 0)
    {
        usleep(15000);
    }
    while (philo->end[0] != 0)
    {
        printf("ROUTINE :  philo id is :%d\n", philo->id);
        if (philo->n_eat == philo->end[1])
            break;
        ft_takefork_r(philo);
        ft_eat(philo);
        ft_putfork_r(philo);
        ft_sleep(philo);
        ft_think(philo);
    }

    return NULL;
}

void *death_check(void *philos)
{
    int time;
    t_data *philo;

    philo = (t_data *)philos;
    while (1)
    {
        time = ft_timestamp(philo->t_start);
        if ((time - philo->t_last) > philo->t2_die)
        {
            pthread_mutex_lock(philo->control);
            ft_printstat(philo, "died!\n");
            philo->end[0] = 0;
            pthread_mutex_unlock(philo->control);
            break;
        }
    }
    return NULL;
}

void    *routine2(void  *philo)
{
    t_data  *ph;

    ph = (t_data *) philo;
    printf("ph_%d in pthread\n", ph->id);

    return (NULL);
}

int ft_startphilo(t_data *philo, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        // printf("philo_%d in startphilo\n", philo[i].id);
        if (pthread_create(&philo[i].thread, NULL, routine2, &philo[i]) != 0)
            return (0);
        // pthread_create(&philo[i].thread, NULL, routine2, &philo[i]);
        usleep(100);
        i++;
    }
    // pthread_create(&philo->death_check, NULL, death_check, &philo);
    // i = 0;
    while (i < size)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (0);
        i++;
    }
    // if (pthread_join(philo->death_check, NULL) != 0)
    //     return (0);
    return (1);
}