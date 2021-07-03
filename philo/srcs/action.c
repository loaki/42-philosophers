#include "philo.h"

void    philo_eat(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    pthread_mutex_lock(&(data->forks[philo->left_fork]));
	print_action(data, philo, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	print_action(data, philo, "has taken a fork");
    philo->last_eat = get_time();
    philo->eating = 1;
	print_action(data, philo, "is eating");
    usleep(data->time_eat * 1000);
    pthread_mutex_unlock(&(data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
    (philo->nb_eat)++;
    philo->eating = 0;
}

void    print_action(t_data *data, t_philo *philo, char *str)
{
    pthread_mutex_lock(&(data->writing));
    printf("%-7lli %d %s\n", get_time() - data->time_start, philo->pos + 1, str);
    pthread_mutex_unlock(&(data->writing));
}