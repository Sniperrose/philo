#include "includes/philo.h"

int ft_ms2usec(int  ms)
{
    int usec;

    usec = ms * 1000;
    return (usec);
}

void    ft_print(int ms, int id, char *msg)
{
    printf("%dms | philo[%d] %s\n", ms, id, msg);
}

void    *ft_one_philo(t_data *philo)
{
    pthread_mutex_lock(&philo->fork[philo->r_fork]);
    gettimeofday(&philo->t_lasteat, NULL);
    ft_print(ft_timestamp(philo->t_start), philo->id, "took a fork");
    usleep(ft_ms2usec(philo->t2_die));
    if (ft_timestamp(philo->t_lasteat) > philo->t2_die)
    {
        philo->end[0] = 1;
    }
        // ft_print(ft_timestamp(philo->t_start), philo->id, "died");
    pthread_mutex_unlock(&philo->fork[philo->r_fork]);
    return (NULL);
}

void	*routine(void *philos)
{
    t_data  *philo;

    philo = (t_data *) philos;

    // printf("%lums | ", ft_timestamp(philo->t_start));
    // printf("philo[%d] started\n", philo->id);
    // pthread_mutex_lock(&philo[philo->r_fork].fork);
    // printf("[%d] took a right fork[%d]\n", philo->id, philo->r_fork);
    // pthread_mutex_unlock(&philo[philo->r_fork].forks);


    // printf("[%lums] philo[%d]\n", ft_timestamp(philo->t_start), philo->id);
    if (philo->size == 1)
        return(ft_one_philo(philo));
    // else
        printf("[%dms] philo[%d]\n", ft_timestamp(philo->t_start), philo->id);

    while (philo->end[0] == 0 || philo->end[1] != 0)
	return (NULL);	
}
