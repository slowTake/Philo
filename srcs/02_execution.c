#include "philo.h"

int	execution_main(t_data *data)
{
	if (init_main(data) != 0)
		return (1);
	init_threads(data);
	if (monitor(data) != 0)
		return (1);
	return (0);
}

int	init_main(t_data *data)
{
	if (init_fork(data) != 0)
		return (1);
	if (init_ctrl_mutexes(data) != 0) // This function needs cleanup logic
		return (1);
	init_philo_data(data);
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
}

int monitor(t_data *data)
{
	int i = 0;

	while(i < data->philo_count)
	{

	}
}

