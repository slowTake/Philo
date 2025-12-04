#include "philo.h"

int	execution_main(t_data *data)
{
	if (init_resources(data) != 0)
		return (1);
	if (init_threads(data) != 0)
		return (1);
	while(data->stop_flag == 0)
		monitor(data);
	cleanup_all(data);
	return (0);
}

int	init_resources(t_data *data)
{
	if (init_fork(data) == 1) // 
		return (1);
	if (init_ctrl_mutexes(data) == 1) // cleaned if fails
	{
		cleanup_mutexes(data, data->philo_count);
		return (1);
	}
	if (init_philo_data(data) == 1) // No cleanup
		return (1);
	return (0);
}

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create != 0)
		{
			cleanup_threads(data, i);
			return (1);
		}
		i++;
	}
	return(0);
}

void monitor(t_data *data)
{
	int i;
	
	while(data->stop_flag == 0)
	{
		i = 0;
		while(i < data->philo_count)
		{
			pthread_mutex_lock(&data->data_mutex);
			long time_elapsed = get_current_time_ms() - data->philosophers[i].last_meal_time;
			if(time_elapsed > data->time_to_die)
			{
				data->stop_flag = 1;
				pthread_mutex_unlock(&data->data_mutex);
				printf(data, data->philosophers[i].p_id, "dedge");
				return;
			}
				pthread_mutex_unlock(&data->data_mutex);			
				i++;
		}
		usleep(1000);
	}
}

void print_stats(t_data *data)
{
	
}