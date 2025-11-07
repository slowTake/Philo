#ifndef STRUCTS_H
# define SRUCTS_H

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	int				meals_eaten;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_to_eat;
	long			start_time;
	int				simulation_end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	data_mutex;
	t_philo			*philosophers;
}					t_data;

typedef enum e_error_type
{
	E_NOT_DIGIT,
	E_TOO_MANY_ARGS,
	E_TOO_FEW_ARGS,
	E_NOT_POSITIVE,
}					t_error_type;

#endif
