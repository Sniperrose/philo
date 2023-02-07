#include "includes/philo.h"

void	ft_free(t_data *philo, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		pthread_mutex_destroy(&philo[i].fork);
		pthread_mutex_destroy(&philo[i].eat);
	}
	pthread_mutex_destroy(philo->control);
	pthread_mutex_destroy(philo->msg);
	free(philo->end);
	free(philo);
}