/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:08:53 by pnurmi            #+#    #+#             */
/*   Updated: 2026/01/22 14:07:54 by pnurmi           ###   ########.fr       */
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

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->p_id % 2 == 0)
		usleep(1500);
	while (simulation_finished(data) == 0)
	{
		print_status(data, philo->p_id, "is thinking");
		if (data->philo_count % 2 != 0)
			usleep(500);
		take_forks(philo);
		if (simulation_finished(data) != 0)
			break ;
		print_status(data, philo->p_id, "is eating");
		update_last_meal_time(philo);
		usleep(data->time_to_eat * 1000);
		put_forks(philo);
		print_status(data, philo->p_id, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	return (NULL);
}
