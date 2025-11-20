#include "philo.h"

int execution_main(t_data *data)
{
	if (init_main(data) != 0)
		return (1);
	// create threads here
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
