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

// Protypes

int	isdigit(int c);
int	error_msg(t_error_type type);
int	cleanup(void);
int	input_validation(int argc, char **argv, t_data data);
int	input_assignment(char **argv, t_data data);
int	parsing(int argc, char **argv, t_data data);
int	ft_strtol(const char *str);
int	err_msg(const char *str);
int	err_invalid(void);

#endif
