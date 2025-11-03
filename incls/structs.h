#ifndef STRUCTS_H
# define SRUCTS_H

# include "philo.h"

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		last_meal;
	int				meals_eaten;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philos_num;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				meals_to_eat;
	long			start_time;
	int				simulation_end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	data_mutex;
	t_philo			*philosophers;
}					t_data;

#endif
