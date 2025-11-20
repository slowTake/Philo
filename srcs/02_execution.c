#include "philo.h"

int execution_main(t_data data, t_philo philo)
{
	init_main(data);
	
}

int	init_main(t_data *data)
{
	if (init_fork(data) != 0)
		return (1);
	if (init_ctrl_mutexes(data) != 0)
	{
		cleanup_mutexes(data, data->philo_count);
		return (1); // cleanup	
	}
}
