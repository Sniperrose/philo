#include "includes/philo.h"

void ft_printtest(t_arg *arg)
{
    printf("N: %d\n", arg->size);
    printf("t2_die: %d\n", arg->die);
    printf("t2_eat: %d\n", arg->eat);
    printf("t2_sleep: %d\n", arg->sleep);
    printf("n_eat: %d\n", arg->n_eat);
}
void ft_ptest(t_data *philo, int size)
{
    int i = 0;
    while (i < size)
    {
        // if (pthread_mutex_lock(philo[i].control) == 0)
        if (pthread_mutex_lock(philo[i].message) == 0)
            printf("mutex lock succ!\n");
        printf("id: %d\n", philo[i].id);
        ft_printtest(philo[i].arg);
        printf("forks:\t%d&%d\n", philo[i].r_sidefork_id, philo[i].l_sidefork_id);
        printf("n_eaten: %d, t_last: %ld\n", philo[i].n_eaten, philo[i].t_start.tv_usec);
        // if (pthread_mutex_unlock(philo[i].control) == 0)
        if (pthread_mutex_unlock(philo[i].message) == 0)
            printf("mutex unlock succ!\n\n");
        i++;
    }
}

int ft_getargs(t_arg *arg, char **argv)
{
    arg->size = ft_atoi(argv[1]);
    if (arg->size <= 0 || arg->size > 200)
		return (ft_msg("Number of philos must be 0 < N < 201\n"));
    arg->die = ft_atoi(argv[2]);
    arg->eat = ft_atoi(argv[3]);
    arg->sleep = ft_atoi(argv[4]);
    if (arg->die <= 0 || arg->eat <= 0 || arg->sleep <= 0)
		return (ft_msg("Error in args!\n"));
    if (argv[5] && ft_atoi(argv[5]) <= 0)
		return (ft_msg("Error in args!\n"));
    else if (!argv[5])
        arg->n_eat = -1;
    else
        arg->n_eat = ft_atoi(argv[5]);
    return (1);
}

int main(int argc, char **argv)
{
    t_arg   arg;
    t_data  *philo;

    if (argc != 5 && argc != 6)
	{
		printf("TIP: number_of_philosophers time_to_die time");
		printf("_to_eat time_to_sleep [number_of_times_must_eat]\n");
		return (0);
	}
    if (!ft_getargs(&arg, argv))
		return (0);
    philo = malloc(sizeof(t_data) * arg.size);
    if (!philo)
        return (ft_msg("Err in malloc philo!\n"));
    if (!ft_init(&arg, philo))
        return (ft_free(philo));
    if (!ft_startroutine(philo, arg.size))
        return (ft_free(philo));
    // ft_printtest(&arg);
    // ft_ptest(philo, arg.size);
    ft_free(philo);
    return (0);
}