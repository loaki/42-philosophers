#include "philo.h"

int start(t_data *data)
{
    int i;

    i = 0;
    data->time_start = get_time()
    while (i < data->nb_philo)
	{
		if (pthread_create(&(data->philo[i].thread_id), NULL, p_thread, &(data->philo[i])))
			return (1);
		phi[i].t_last_meal = get_time();
		i++;
	}
}