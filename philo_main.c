#include "includes/philo.h"

void	ft_print_args(t_times args);

int	ft_check_get_args(char **argv, t_times *args)
{
	int	size;

	size = ft_atoi(argv[1]);
	if (size <= 0 || size > 200)
		return (ft_msg("N of philos must be 0 < N < 201\n"));
	args->die = ft_atoi(argv[2]);
	args->eat = ft_atoi(argv[3]);
	args->sleep = ft_atoi(argv[4]);
	if (args->die <= 0 || args->eat <= 0 || args->sleep <= 0)
		return (ft_msg("Args cant be negative!\n"));
	if (argv[5] && ft_atoi(argv[5]) <= 0)
		return (ft_msg("Number must eat cant be 0 or less!\n"));
	return (1);
}

int main(int argc, char **argv)
{
	t_times	*args;

	args = NULL;
	if (argc != 5 && argc != 6)
	{
		printf("TIP: number_of_philosophers time_to_die time");
		printf("_to_eat time_to_sleep\n[number_of_times_must_eat]");
		return (0);
	}
	int	i = ft_check_get_args(argv, args);
	if (i == 0)
		return (ft_msg("Error_args!\n"));
	ft_print_args(*args);
    return 0;
}

void	ft_print_args(t_times args)
{
	printf("t2_die: %d\n", args.die);
	printf("t2_eat: %d\n", args.eat);
	printf("t2_sleep: %d\n", args.sleep);
}


// int ft_getargs(char **argv, int *args)
// {
//     args[0] = ft_atoi(argv[2]);
//     args[1] = ft_atoi(argv[3]);
//     args[2] = ft_atoi(argv[4]);
//     if (args[0] <= 0 || args[1] <= 0 || args[2] <= 0)
//         return (ft_msg("Unvalid arg!\n"));
//     if (argv[5])
//         args[3] = ft_atoi(argv[5]);
//     if (args[3] <= 0)
//         return (ft_msg("Unvalid nunber must eat!\n"));
//     if (!argv[5])
//         args[3] = -1;
//     return (1);
// }
// void     ft_init_args(t_data *philo, char **argv, int size, int *end)
// {
//     int i;
//     struct timeval time;
    
//     i = 0;
//     if (argv[5])
//         end[1] = ft_atoi(argv[5]);
//     else
//         end[1] = -1;
//     gettimeofday(&time, NULL);
//     while (i < size)
//     {
//         philo[i].size = size;
//         philo[i].t2_die = ft_atoi(argv[2]);
//         philo[i].t2_eat = ft_atoi(argv[3]);
//         philo[i].t2_sleep = ft_atoi(argv[4]);
//         philo[i].id = i;
//         philo[i].l_fork = (i + 1) % size;
//         philo[i].r_fork = i;
//         philo[i].t_start = time;
//         philo[i].end = end;
//         philo[i].fork = philo->fork;
//         philo[i].control = philo->control;
//         i++;
//     }
// }

// int ft_init_mutex(t_data *philo, int size)
// {
//     int i;

//     philo->fork = malloc(sizeof(pthread_mutex_t) * size);
//     if (!philo->fork)
//         return (1);
//     i = 0;
//     while(i < size)
// 	{
// 		if (pthread_mutex_init(&philo->fork[i], NULL) != 0)
// 			return (ft_msg("Mutex_init error!\n"));
// 		i++;
// 	}
//     philo->control = malloc(sizeof(pthread_mutex_t) * 1);
//     if (!philo->control)
//         return (1);
//     pthread_mutex_init(philo->control, NULL);
//     return (0);
// }

// void	ft_test(t_data *philo, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("philo[%d], t2_die:%d, t2_eat:%d, t_sleep:%d", 
// 			philo[i].id, philo[i].t2_die, philo[i].t2_eat, philo[i].t2_sleep);
// 		printf(" | forks[%d&%d]", philo[i].r_fork, philo[i].l_fork);
// 		// printf(" | n_eat:%d\n", philo[i].n_eat);
// 		i++;
// 	}
// }

// int ft_init(char **argv, t_data *philo)
// {
//     int size;
//     int *end;

//     size = ft_atoi(argv[1]);
//     if(size <= 0 || size > 200 || (argv[5] && ft_atoi(argv[5]) <= 0))
//         return (0);
//     philo = malloc(sizeof(t_data) * size);
//     if (!philo)
//         return (0);
//     philo = memset(philo, 0, size);
//     end = malloc(sizeof(int) * 2);
//     if (!end)
//         return (0);
//     end = memset(end, 0, 2);
//     if (ft_init_mutex(philo, size) != 0)
//         return (0);
//     ft_init_args(philo, argv, size, end);
//     return (1);
// }