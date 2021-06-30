#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;

    if(!(data = malloc(sizeof(t_data))))
        return(free_philo(data, "malloc error\n"));
    if(!(init_data(data, ac, av)))
        return(free_philo(data, "arguments error\n"));
    if(!(init_mutex(data)))
        return(free_philo(data, "mutex error\n"));
    if(!(start(data)))
        return(free_philo(data, "loop error\n"));
}