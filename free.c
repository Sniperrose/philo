#include "includes/philo.h"

void free_mutex(t_data	*philo, int	size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		pthread_mutex_unlock(&philo->fork[i]);
		pthread_mutex_destroy(&philo->fork[i]);
		i++;
	}
	free(philo->fork);
	free(philo->control);
}

void	free_thread(t_data *philos, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		pthread_detach(philos[i].thread);
		i++;
	}
}