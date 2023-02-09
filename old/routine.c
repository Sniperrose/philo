#include "includes/philo.h"

void    ft_takefork_r(t_data *philo)
{
    pthread_mutex_lock(&philo[philo->r_fork].fork);
    ft_printstat(philo, "took a fork\n");   
}
void    ft_putfork_r(t_data *philo)
{
    pthread_mutex_unlock(&philo[philo->r_fork].fork);
    ft_printstat(philo, "put a fork\n");
}

void    ft_eat(t_data *philo)
{
    // pthread_mutex_lock(&philo->eat);
    pthread_mutex_lock(&philo->eat);
    ft_printstat(philo, "start eating ...\n");
    usleep(philo->t2_eat * 1000);
    philo->t_last = ft_timestamp(philo->t_start);
    // pthread_mutex_unlock(&philo->eat);
    pthread_mutex_unlock(&philo->eat);
    philo[philo->id].n_eat++;
}

void    ft_sleep(t_data *philo)
{
    ft_printstat(philo, "sleep!\n");
    usleep(philo->t2_sleep * 1000);
}

void    ft_think(t_data *philo)
{
    ft_printstat(philo, "thinking...\n");
}

void	*routine(void *philos)
{
    t_data  *philo;

    philo = (t_data *) philos;

    if ((philo->id % 2) != 0)
        usleep(10);
    while(philo->end[0] != 0)
    {
        if (philo->n_eat == philo->end[1])
            break;
        ft_takefork_r(philo);
        ft_eat(philo);
        ft_putfork_r(philo);
            // printf("last_eat = %d\n", philo->t_last);
        ft_sleep(philo);
        ft_think(philo);
    }
    return NULL;
}

void    *death_check(void *philos)
{
    int     time;
    t_data *philo;

    philo = (t_data *)philos;
    while (1)
    {
    time = ft_timestamp(philo->t_start);
    // printf("time = %d, t_last = %d\n", time, philo->t_last);
    if ((time - philo->t_last) > philo->t2_die)
    {
        pthread_mutex_lock(philo->control);
        ft_printstat(philo, "died!\n");
        philo->end[0] = 0;
        pthread_mutex_unlock(philo->control);
        break;
    }
    usleep(10000);
    }
    // ft_printstat(philo, "--test\n"); 
    return NULL;
}

void    *routine2(void  *philo)
{
    t_data  *ph;

    ph = (t_data *) philo;
    ft_print(ph, "test ...\n");
        // printf("ph_%d in pthread\n", ph->id);
    return (NULL);
}

int ft_startphilo(t_data *philo, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (pthread_create(&philo[i].thread, NULL, routine2, &philo[i]) != 0)
            return (0);
        usleep(100);
        i++;
    }
    // i = 0;
    // while (i < size)
    // {
    //     if (pthread_create(&philo->death_check, NULL, death_check, &philo[i]) != 0)
    //         return (0);
    //     i++;
    // }
    i = 0;
    while(i < size)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (0);
        i++;
    }
    // if (pthread_join(philo->death_check, NULL) != 0)
    //     return (0);
    return (1);
}