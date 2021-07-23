#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	free_philo(t_data *data, char *str)
{
	int	i;

	i = data->nb_philo;
	printf("%s", str);
	if (data->end == 1)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->writing);
	}
	return (0);
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

void	sleep_us(long time)
{
	long long	start;

	start = get_time();
	while (get_time() < start + time)
		usleep(100);
}
