#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (parsing(argc, argv, &data) != 0)
		return (1);
	execution_main(&data);
	// monitor();
	cleanup_data(&data);
	return (0);
}
