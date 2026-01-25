/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:08:53 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/25 15:24:09 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	execution_main(t_data *data)
{
	if (init_resources(data) != 0)
	{
		cleanup_data(data);
		return (1);
	}
	if (init_threads(data) != 0)
	{
		cleanup_data(data);
		return (1);
	}
	monitor(data);
	wait_for_threads(data);
	cleanup_data(data);
	return (0);
}

int	init_resources(t_data *data)
{
	if (init_fork(data) == 1)
		return (1);
	if (init_ctrl_mutexes(data) == 1)
	{
		cleanup_mutexes(data, data->philo_count);
		return (1);
	}
	if (init_philo_data(data) == 1)
		return (1);
	return (0);
}

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_current_time_ms();
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philosophers[i].t_id, NULL, &philo_routine,
				&data->philosophers[i]) != 0)
		{
			cleanup_threads(data, i);
			return (1);
		}
		pthread_mutex_lock(&data->data_mutex);
		data->philosophers[i].last_meal_time = data->start_time;
		pthread_mutex_unlock(&data->data_mutex);
		i++;
	}
	return (0);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mutex);
	philo->last_meal_time = get_current_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->data_mutex);
}
