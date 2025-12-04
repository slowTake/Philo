#include "philo.h"

long long get_time_ms(void)
{
	struct timeval tv;
	long long time_in_ms;

	if(gettimeofday(&tv, NULL))
		return(1);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);

	return time_in_ms;
}

int print_status(t_data *data, int philo_id, const char *status)
{
	long timestamp;

	if(pthread_mutex_lock(&data->print_mutex)!= 0)
		return(1);
	if(data->stop_flag == 0)
	{
		timestamp = get_time_ms() - data->start_time;
		printf("%ld %d %s\n", timestamp, philo_id, status);
	}
	if(pthread_mutex_unlock(&data->print_mutex) != 0)
		return(1);
	return(0);
}
