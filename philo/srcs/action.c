#include "philo.h"

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	print_action(data, philo, " has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	print_action(data, philo, " has taken a fork");
	philo->eating = 1;
	philo->last_eat = get_time();
	print_action(data, philo, " is eating");
	sleep_us(data->time_eat);
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
	(philo->nb_eat)++;
	philo->eating = 0;
}

void	print_action(t_data *data, t_philo *philo, char *str)
{
	pthread_mutex_lock(&(data->writing));
	ft_putnbr_fd(get_time() - data->time_start, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(philo->pos + 1, 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	pthread_mutex_unlock(&(data->writing));
}
