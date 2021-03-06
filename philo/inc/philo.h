#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_philo{
	int				pos;
	int				left_fork;
	int				right_fork;
	int				eating;
	int				nb_eat;
	long long		last_eat;
	pthread_t		thread_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data{
	int				nb_philo;
	int				end;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			nb_eat;
	long long		time_start;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	writing;
}	t_data;

int			ft_atoi(const char *str);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlen(const char *str);
void		ft_putchar_fd(char c, int fd);
void		init_philo(t_data *data);
int			init_data(t_data *data, int ac, char **av);
int			init_mutex(t_data *data);

void		*thread_loop(void *philo_ptr);
void		check_philo(t_data *data);
int			start(t_data *data);

long long	get_time(void);
int			free_philo(t_data *data, char *str);
int			is_digit(char *str);
void		sleep_us(long time);

void		philo_eat(t_philo *philo);
void		print_action(t_data *data, t_philo *philo, char *str);

#endif
