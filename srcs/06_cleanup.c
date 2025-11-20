#include "philo.h"

void	cleanup_philos(t_data *data)
{
	free(data->philosophers);
	free(data->forks);
}

void	cleanup_mutexes(t_data *data, int mutexes)
{
	int	j;

	j = 0;
	while (j < mutexes)
	{
		pthread_mutex_destroy(&data->forks[j]);
		j++;
	}
	pthread_mutex_destroy(&data->print_mutex);
}

void cleanup_main(t_data *data)
{
	cleanup_philos(data);
	cleanup_mutexes(data, data->philo_count);
}

void cleanup_threads(t_data *data, int i)
{
	while (i >= 0)	
	{
		pthread_join(data->philosophers[i].thread_id, NULL);
		i--;
	}
}	
