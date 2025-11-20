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

void cleanup_data(t_data *data)
{
	cleanup_philos(data);
	cleanup_mutexes(data, data->philo_count);
}
