/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:09:04 by pnurmi            #+#    #+#             */
/*   Updated: 2025/12/22 11:10:29 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_philos(t_data *data)
{
	free(data->philosophers);
	free(data->forks);
}

void	cleanup_mutexes(t_data *data, int mutexes)
{
	int	j;

	j = 0;
	while (j < mutexes)
	{
		pthread_mutex_destroy(&data->forks[j]);
		j++;
	}
	pthread_mutex_destroy(&data->print_mutex);
}

void	cleanup_main(t_data *data)
{
	cleanup_philos(data);
	cleanup_mutexes(data, data->philo_count);
}

void	cleanup_threads(t_data *data, int i)
{
	while (i >= 0)
	{
		pthread_join(data->philosophers[i].t_id, NULL);
		i--;
	}
}

int	simulation_finished(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->data_mutex);
	stopped = data->stop_flag;
	pthread_mutex_unlock(&data->data_mutex);
	return (stopped);
}
