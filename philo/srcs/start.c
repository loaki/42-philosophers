#include "philo.h"

void	*thread_loop(void *philo_ptr)
{
	int				i;
    t_philo	*philo;
	t_data			*data;

	i = 0;
	philo = (t_philo *)philo_ptr;
	data = philo->data;
	print_action(data, philo, "is alive");
	while (get_time() - philo->last_eat < data->time_die)
	{
		philo_eat(philo);
		print_action(data, philo, "is sleeping");
		usleep(data->time_sleep);
		print_action(data, philo, "is thinking");
	}
    return(NULL);
}

void	check_philo(t_data *data)
{
	int i;
	int nb_eat;

	while (nb_eat != data->nb_philo)
	{
		i = -1;
		nb_eat = 0;
		while (++i < data->nb_philo)
		{
			if (get_time() - data->philo[i].last_eat > data->time_die)
			{
				print_action(data, &(data->philo[i]), "died");
				return;
			}
			if (data->philo[i].nb_eat >= data->nb_eat)
				nb_eat++;
		}
	}
}

int start(t_data *data)
{
    int i;

    i = 0;
    data->time_start = get_time();
    while (i < data->nb_philo)
	{
		if (pthread_create(&(data->philo[i].thread_id), NULL, thread_loop, &(data->philo[i])))
			return (0);
		data->philo[i].last_eat = get_time();
		i++;
		usleep(1000);
	}
	check_philo(data);
	free_philo(data, "");
    return(1);
}