#include "philo.h"

int	alloc_memory(t_data *data)
{
	data->philosophers = (t_philo *)malloc(sizeof(t_philo) * data->philo_count);
	if (data->philosophers == NULL)
		return (err_msg("Phillo alloc failed"));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->philo_count);
	if (data->forks == NULL)
	{
		free(data->philosophers);
		data->philosophers = NULL;
		return (err_msg("Fork alloc failed"));
	}
	return (0);
}
void	cleanup_philos(t_data *data)
{
	free(data->philosophers);
	data->philosophers = NULL;
	free(data->forks);
	data->forks = NULL;
}
void	cleanup_mutexes(t_data *data, int mutexes)
{
	int	j;

	free(data->forks);
	data->forks = NULL;
	j = 0;
	while (j < mutexes)
	{
		pthread_mutex_destroy(&data->forks[j]);
		j++;
	}
}

void cleanup_data(t_data *data)
{
	cleanup_philos(data);
	cleanup_mutexes(data, data->philo_count);
}
