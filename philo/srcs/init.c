#include "philo.h"

void    init_philo(t_data *data)
{
	int i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		data->philo[i].pos = i;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nb_philo;
		data->philo[i].eating = 0;
		data->philo[i].last_eat = 0;
		data->philo[i].nb_eat = 0;
		data->philo[i].data = data;
	}
}

int     init_data(t_data *data, int ac, char **av)
{
    if (ac > 6 || ac <= 4 || !is_digit(av[1]) || !is_digit(av[2]) || !is_digit(av[3]) || !is_digit(av[4]) \
		 || (ac == 6 && !is_digit(av[5])))
		return (0);
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (data->nb_philo < 1 || data->time_die <= 0 || data->time_eat <= 0
		|| data->time_sleep <= 0 || (ac == 6 && ft_atoi(av[5]) <= 0))
		return (0);
	data->nb_eat = -1;
	if (ac == 6 && ft_atoi(av[5]) > 0)
		data->nb_eat = ft_atoi(av[5]);
	init_philo(data);
	return (1);
}

int	init_mutex(t_data *data)
{
	int i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (0);
	}
	if (pthread_mutex_init(&(data->writing), NULL))
		return (0);
	return (1);
}