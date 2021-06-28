#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;

    if(!(data = malloc(sizeof(t_data))))
        return(free_philo(data, "malloc"));
    if(!(init_data(data, ac, av)))
        return(free_philo(data, "arguments"));
    if(!(init_mutex(data)))
        return(free_philo(data, "mutex"));
    if(!(start(data)))
        return(free_philo(data, "loop"));
    printf("%ld\n", data->nb_eat);
    size_t time;
    size_t stime;
    stime = get_time();
    printf("%lu\n", stime);
    sleep(1);
    time = get_time();
    printf("%lu\n",time - stime);
}