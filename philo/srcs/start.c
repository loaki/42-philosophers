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
	while (data->nb_eat == -1 || philo->nb_eat < data->nb_eat)
	{
		philo_eat(philo);
		print_action(data, philo, "is sleeping");
		usleep(data->time_sleep * 1000);
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
			if (!data->philo[i].eating && get_time() - data->philo[i].last_eat > data->time_die)
			{
        		pthread_mutex_lock(&(data->writing));
				printf("%-7lli %d %s\n", get_time() - data->time_start, i + 1, "died");
				return;
			}
			if (data->nb_eat != -1 && data->philo[i].nb_eat >= data->nb_eat)
				nb_eat++;
			usleep(50);
		}
	}
    pthread_mutex_lock(&(data->writing));
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
		pthread_detach(data->philo[i].thread_id);
		data->philo[i].last_eat = get_time();
		usleep(100);
		i++;
	}
	check_philo(data);
	free_philo(data, "");
    return(1);
}