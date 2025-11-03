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

int	isdigit(int c);

typedef enum e_error_type
{
	E_NOT_DIGIT,
	E_TOO_MANY_ARGS,
	E_TOO_FEW_ARGS,
} t_error_type;

#endif
