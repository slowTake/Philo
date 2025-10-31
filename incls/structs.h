#ifndef STRUCTS_H
# define SRUCTS_H

#include "philo.h"
typedef struct t_data
{
	int philos;
	long time_to_die;
	long time_to_eat;
	long time_to_sleep;
	long start_time;
	pthread_mutex_t print_mutex;
	pthread_mutex_t data_mutex;
	int stop_flag;
}			t_data;

#endif
