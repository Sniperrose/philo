#include "includes/philo.h"

void ft_takefork_r(t_data *philo)
{
<<<<<<< HEAD
    pthread_mutex_lock(&philo[philo->r_fork].fork);
    ft_printstat(philo, "took a fork\n");
}
void ft_putfork_r(t_data *philo)
=======
    pthread_mutex_lock(&philo->fk[philo->r_fork]);
    // pthread_mutex_lock(&philo[philo->r_fork].fork);

    ft_printstat(philo, "has taken a r_fork\n");   
    // printf("r_fork id: %d\n", philo->r_fork);

}

void    ft_takefork_l(t_data *philo)
>>>>>>> 3feeb5c25cac111919378625bcee0f5a2791c476
{
    pthread_mutex_lock(&philo->fk[philo->l_fork]);
    // pthread_mutex_lock(&philo[philo->l_fork].fork);
    ft_printstat(philo, "has taken a l_fork\n");   
    // printf("r_fork id: %d\n", philo->l_fork);

}

void    ft_putfork(t_data *philo)
{
    // printf("in putfork\n");

    pthread_mutex_unlock(&philo->fk[philo->r_fork]);
    pthread_mutex_unlock(&philo->fk[philo->r_fork]);

    // pthread_mutex_unlock(&philo[philo->r_fork].fork);
    // pthread_mutex_unlock(&philo[philo->l_fork].fork);
    // printf("in putfork\n");

    // ft_printstat(philo, "put a fork\n");
}

void ft_eat(t_data *philo)
{
    pthread_mutex_lock(&philo->eat);
    ft_printstat(philo, "is eating\n");
    usleep(philo->t2_eat * 1000);
    philo->t_last = ft_timestamp(philo->t_start);
<<<<<<< HEAD
=======
    // printf("%d t_lastest %d\n", philo->id, philo->t_last);
>>>>>>> 3feeb5c25cac111919378625bcee0f5a2791c476
    pthread_mutex_unlock(&philo->eat);
    philo->n_eat++;
    // printf("n_eat %d\n", philo->n_eat);
    // printf("in eat\n");
    // printf("in eat end[0] = %d\n", philo->end[0]);
}

void ft_sleep(t_data *philo)
{
    // printf("in sleep\n");
    ft_printstat(philo, "is sleeping\n");
    usleep(philo->t2_sleep * 1000);
}

void ft_think(t_data *philo)
{
    ft_printstat(philo, "is thinking\n");
}

void *routine(void *philos)
{
    t_data *philo;

<<<<<<< HEAD
    philo = (t_data *)philos;

    if ((philo->id % 2) != 0)
    {
        usleep(15000);
    }
    while (philo->end[0] != 0)
    {
        printf("ROUTINE :  philo id is :%d\n", philo->id);
=======
    philo = (t_data *) philos;
    while(philo->end[0] != 0)
    {
        if (philo->size == 1)
        {
            usleep(philo->t2_die * 1000);
                return (NULL);
        }
        if ((philo->id % 2) != 0)
            usleep(15000);
>>>>>>> 3feeb5c25cac111919378625bcee0f5a2791c476
        if (philo->n_eat == philo->end[1])
            break;
        ft_takefork_r(philo);
        ft_takefork_l(philo);
        ft_eat(philo);
<<<<<<< HEAD
        ft_putfork_r(philo);
=======
        // printf("in routine\n");
        ft_putfork(philo);
        // printf("in routine after release fork\n");
>>>>>>> 3feeb5c25cac111919378625bcee0f5a2791c476
        ft_sleep(philo);
        // printf("in routine after sleep\n");
    }
<<<<<<< HEAD

=======
    ft_think(philo);
>>>>>>> 3feeb5c25cac111919378625bcee0f5a2791c476
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
<<<<<<< HEAD
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
=======
        usleep(5000);
    }
    // ft_printstat(philo, "--test\n"); 
    return NULL;
}

// void    *routine2(void  *philo)
// {
//     t_data  *ph;

//     ph = (t_data *) philo;
//     ft_print(ph, "test ...\n");
//         // printf("ph_%d in pthread\n", ph->id);
//     return (NULL);
// }
>>>>>>> 3feeb5c25cac111919378625bcee0f5a2791c476

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
<<<<<<< HEAD
    // pthread_create(&philo->death_check, NULL, death_check, &philo);
    // i = 0;
    while (i < size)
    {
=======
    // if (pthread_create(&philo->death_check, NULL, death_check, &philo) != 0)
    //         return (0);
    i = 0;
    while (i < size)
    {
        if (pthread_create(&philo[i].thread, NULL, death_check, &philo[i]) != 0)
            return (0);
        usleep(100);
        i++;
    }
    i = 0;
    while(i < size)
    {
>>>>>>> 3feeb5c25cac111919378625bcee0f5a2791c476
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (0);
        i++;
    }
    // if (pthread_join(philo->death_check, NULL) != 0)
    //     return (0);
    return (1);
}