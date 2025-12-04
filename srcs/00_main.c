#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if( argc != 5 && argc != 6)
		return(err_invalid);
	if (parsing(argc, argv, &data) != 0)
		return (1);
	execution_main(&data);
	cleanup_data(&data);
	return(0);
}
