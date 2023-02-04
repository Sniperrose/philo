#include "includes/philo.h"


int	ft_atoi(const char *nptr)
{

	int	i;
	int	sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] > 7 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (47 < nptr[i] && nptr[i] < 58)
	{
		num = 10 * num + (nptr[i] - '0');
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
		i++;
	}
	return (num * sign);
}

int	ft_err_msg(const char *msg)
{
	if (msg)
	{
		printf("%s", msg);
	}
	return (-1);
}

void free_mutex(t_data	*philo, int	size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		pthread_mutex_unlock(&philo[i].forks);
		pthread_mutex_destroy(&philo[i].forks);
		i++;
	}
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