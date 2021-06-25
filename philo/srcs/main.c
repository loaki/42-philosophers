#include "philo.h"

int main(int ac, char **av)
{
    size_t time;
    size_t stime;

    stime = get_time();
    printf("%lu\n", stime);
    sleep(1);
    time = get_time();
    printf("%lu\n",time - stime);
}