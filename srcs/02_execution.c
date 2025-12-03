#include "philo.h"

int	execution_main(t_data *data)
{
	if (init_resources(data) != 0)
		return (1);
	if (monitor(data) != 0)
		return (1);
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
	// if (init_threads(data) == 1) // cleaned if fails
	// 	return (1); << move init thread to execution
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

int monitor(t_data *data)
{
	int i = 0;

	while(i < data->philo_count)
	{

	}
}

