#include "includes/philo.h"

// void	*routine(void *philos)
// {
//     t_data  *philo;

//     philo = (t_data *) philos;


//     printf("philo[%d]\n", philo->id);
// 	return (NULL);	
// }


void	*routine(void *philos)
{
    t_data  *philo;

    philo = (t_data *) philos;


    // printf("philo[%d]\n", philo->id);

    // if ((philo->id % 2) != 0)
    // {
    //     printf("[%d] must wait\n", philo->id);
    //     usleep(100);
    // }
    // pthread_mutex_lock(&philo[philo->l_fork].forks);
    // printf("[%d] took a left fork[%d]\n", philo->id, philo->l_fork);
    pthread_mutex_lock(&philo[philo->r_fork].forks);
    printf("[%d] took a right fork[%d]\n", philo->id, philo->r_fork);

    // pthread_mutex_lock(philo->control);
    // printf("lock cntl\n");
    // usleep(100);

    // pthread_mutex_unlock(&philo[philo->l_fork].forks);
    // printf("-[%d] put a left fork[%d]\n", philo->id, philo->l_fork);
    pthread_mutex_unlock(&philo[philo->r_fork].forks);
    // printf("-[%d] put a right fork[%d]\n", philo->id, philo->r_fork);
    // pthread_mutex_unlock(philo->control);
	return (philo);	
}