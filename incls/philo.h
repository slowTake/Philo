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

//01_parsing
int	parsing(int argc, char **argv, t_data data);
int	isdigit(int c);
int	input_validation(int argc, char **argv, t_data data);
int	input_assignment(char **argv, t_data data);
int	ft_strtol(const char *str);

//05_error
int	err_invalid(void);
int	err_msg(const char *str);
int	error_msg(t_error_type type);

//utility



//memory
int alloc_memory(t_data *data);

#endif
