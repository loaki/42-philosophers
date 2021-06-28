#include "philo.h"

void	*thread_loop(void *philo_ptr)
{
	int				i;
    t_philo	*philo;
	t_data			*data;

	i = 0;
	philo = (t_philo *)philo_ptr;
	data = philo->data;
    return(NULL);
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
	}
    return(1);
}