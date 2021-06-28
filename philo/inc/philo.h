#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_philo{
    int         pos;
    int         left_fork;
    int         right_fork;
    int         nb_eat;
    size_t      last_eat;
    pthread_t	thread_id;
    struct s_data   *data;
}       t_philo;

typedef struct s_data{
    long	    nb_philo;
	long	    time_die;
	long	    time_eat;
	long	    time_sleep;
	long	    nb_eat;
    size_t      time_start;
    t_philo     philo[200];
    pthread_mutex_t		forks[200];
	pthread_mutex_t		writing;
}           t_data;

int		ft_atoi(const char *str);

void    init_philo(t_data *data);
int     init_data(t_data *data, int ac, char **av);
int	    init_mutex(t_data *data);

void	*thread_loop(void *philo_ptr);
int start(t_data *data);

size_t	get_time();
int		free_philo(t_data *data, char *str);
int     is_digit(char *str);

#endif