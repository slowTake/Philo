#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// ours
# include "structs.h"

// Protypes

int		isdigit(int c);
int		error_msg(t_error_type type);
int		cleanup(void);
void	input_validation(int argc, char **argv, t_data data);
void	parsing(char **argv, t_data data);

#endif
