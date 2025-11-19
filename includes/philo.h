#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// ours
# include "structs.h"

// 01_parsing
int	parsing(int argc, char **argv, t_data data);
int	isdigit(int c);
int	input_validation(int argc, char **argv, t_data data);
int	input_assignment(char **argv, t_data data);
int	ft_strtol(const char *str);

// 04_error
int	err_invalid(void);
int	err_msg(const char *str);
int	error_msg(t_error_type type);


// 05_memory
int	alloc_memory(t_data *data);
void cleanup_philos(t_data *data);
void cleanup_mutexes(t_data *data);
void cleanup_threads(t_data *data);
void cleanup_data(t_data *data);

// utility

#endif
