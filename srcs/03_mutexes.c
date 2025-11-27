#include "philo.h"

int	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			cleanup_mutexes(data, i);
			return (1);
		}
		i++;
	}
	return(0);
}

int	init_ctrl_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		cleanup_mutexes(data, data->philo_count);
		return (1);
	}
	return(0);
}

int init_philo_data(t_data *data)
{
	int i = 0;

	while(i < data->philo_count)
	{
		data->philosophers[i].philo_id = i + 1;
		data->philosophers[i].data = data;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].left_fork = &data->forks[i];
		data->philosophers[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		data->philosophers[i].thread_id = 0;
		i++;
	}
	return(0);
}
