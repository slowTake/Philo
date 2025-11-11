#include "philo.h"

int	alloc_memory(t_data *data)
{
	data->philosophers = (t_philo *)malloc(sizeof(t_philo) * data->philos_num);
	if (data->philosophers == NULL)
		return(err_msg("Phillo alloc failed"));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)	* data->philos_num);
	if (data->forks == NULL)
	{
		free(data->philosophers);
		data->philosophers = NULL;
		return(err_msg("Fork alloc failed"));
	}
	return (0);
}
