#include "philo.h"

int	error_msg(t_error_type type)
{
	if (type == E_NOT_DIGIT)
		printf("Not a valid digit");
	if (type == E_TOO_MANY_ARGS)
		printf("too many args");
	if (type == E_TOO_FEW_ARGS)
		printf("too few args");
	return(1);
}

int	err_msg(const char *str)
{
	printf("%s", *str);
	return (1);
}


int	err_invalid(void)
{
	printf("\nPlease enter valid params:");
	printf("\n           Number of philosphers");
	printf("\n           Time to die");
	printf("\n           Time to eat");
	printf("\n           Time to sleep");
	printf("\n           Number of meals to eat (optional)");
	return (1);
}

void	err_cleanup(void)
{

}

void err_clean_fork()
{

}

void cleanup_mutexes(t_data *data, int mutexes)
{
	int j = 0;

	while(j < mutexes)
	{
		pthread_mutex_destroy(&data->forks[j]);
		j++;
	}
}
