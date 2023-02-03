#include "includes/philo.h"

int ft_initialize(char **argv, t_data *philo)
{
    int size;
    int *end;
    int i;

    size = ft_atoi(argv[1]);
    if(size <= 0 || size > 200)
        return (ft_err_msg("Number of philos not valid!\n"));
    philo = malloc(sizeof(t_data) * size);
    if (!philo)
        return (ft_err_msg("Error in creating malloc!\n"));
    end = malloc(sizeof(int) * 2);
    if (!end)
        return (ft_err_msg("Error in creating malloc!\n"));
    end = memset(end, 0, 2);
    philo = memset(philo, 0, size);
    i = 0;
    while (i < size)
    {
        philo[i].id = i;
        philo[i].end = end;
        i++;
    }
    printf("test\n");
    return (0);
}