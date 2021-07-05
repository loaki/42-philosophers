#include "philo.h"

long long	get_time()
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int		free_philo(t_data *data, char *str)
{
	int i;

	i = data->nb_philo;
	printf("%s", str);
	while (--i >= 0)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->writing);
	free(data);
	return(0);
}

int	is_digit(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}