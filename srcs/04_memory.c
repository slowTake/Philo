#include "philo.h"

int	alloc_memory(t_data *data)
{
	data->philosophers = (t_philo *)malloc(sizeof(t_philo) * data->philos_num);
	if (data->philosophers == NULL)
		err_msg("alloc failed");
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)	* data->philos_num);
	if (data->forks == NULL)
	{
		free(data->philosophers);
		data->philosophers = NULL;
		err_msg("alloc failed");
	}
	return (0);
}
