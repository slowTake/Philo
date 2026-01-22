/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:11:01 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/22 17:50:56 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structs.h"
# include <limits.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// 01_parsing
int			parsing(int argc, char **argv, t_data *data);
int			input_validation(int argc, char **argv);
int			input_assignment(int argc, char **argv, t_data *data);
long		ft_strtol(const char *str);

// 02 Execution
int			execution_main(t_data *data);
int			init_resources(t_data *data);
int			init_threads(t_data *data);
void		monitor(t_data *data);
void		*philo_routine(void *arg);
void		update_last_meal_time(t_philo *philo);

// 03_mutexes
int			init_fork(t_data *data);
int			init_ctrl_mutexes(t_data *data);
int			init_philo_data(t_data *data);

// 04_error
int			err_invalid(void);
int			err_msg(const char *str);

// 05_memory
int			alloc_memory(t_data *data);

// 06_cleanup
void		cleanup_philos(t_data *data);
void		cleanup_mutexes(t_data *data, int mutexes);
void		cleanup_threads(t_data *data, int i);
void		cleanup_data(t_data *data);
int			simulation_finished(t_data *data);

// 07_utils
long long	get_current_time_ms(void);
int			print_status(t_data *data, int philo_id, const char *status);
void		wait_for_threads(t_data *data);

// 09_forks
int			take_forks(t_philo *philo);
void		put_forks(t_philo *philo);

#endif
