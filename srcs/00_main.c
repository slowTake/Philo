#include "philo.h"

void	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	philo;

	parsing(argc, argv, *data);
	execution(); // init main, 
	monitor();
	cleanup_data(data);
}
