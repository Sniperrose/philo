#include "includes/philo.h"

void ft_init_threads(t_data *philo, int size)
{
    int i;

    i = 0;
    while(i < size)
	{
		if (pthread_create(&(philo[i].thread), NULL, routine, &philo[i]) != 0)
		{
			printf("error in pthread_create\n");
			return ;
		}
		usleep(50);
		i++;
	}
	
    i = 0;
    while(i < size)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }
	return ;
}
