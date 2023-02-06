#include "includes/philo.h"

void	*routine(void *philos)
{
    t_data  *philo;

    philo = (t_data *) philos;

    // printf("%lums | ", ft_timestamp(philo->t_start));
    // printf("philo[%d] started\n", philo->id);
    // pthread_mutex_lock(&philo[philo->r_fork].forks);
    // printf("[%d] took a right fork[%d]\n", philo->id, philo->r_fork);
    // pthread_mutex_unlock(&philo[philo->r_fork].forks);


    printf("[%lums] philo[%d] ", ft_timestamp(philo->t_start), philo->id);
	printf(" t2_die:%d, t2_eat:%d, t_sleep:%d", 
        philo->t2_die, philo->t2_eat, philo->t2_sleep);
	printf(" | forks[%d&%d]", philo->r_fork, philo->l_fork);
	printf(" | end[0]=%d, end[1]=%d\n", philo->end[0], philo->end[1]);

	return (NULL);	
}
